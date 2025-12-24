#include "include/set_integers.h"

#include <stdio.h>
#include <stdlib.h>

#define SET_DEFAULT_CAPACITY 8
#define SET_MAX_CAPACITY 100

// Data structure
struct set_integers {
    int size;
    int capacity;
    int *set;
};

// Creation
SetIntegers *create_set(int capacity) {
    if(capacity <= 0) {
        capacity = SET_DEFAULT_CAPACITY;
    }

    if(capacity > SET_MAX_CAPACITY) {
        capacity = SET_MAX_CAPACITY;
    }

    SetIntegers *set = calloc(1, sizeof(SetIntegers));

    if(!set) {
        return NULL;
    }

    set->capacity = capacity;
    set->size = 0;
    set->set = calloc(capacity, sizeof(int));

    if(!set->set) {
        free(set);
        return NULL;
    }

    return set;
}

// Destruction
int destroy(SetIntegers **set) {
    if (!set || !*set) {
        return SET_ERROR;
    }

    free((*set)->set);
    free(*set);
    *set = NULL;

    return SET_OK;
}

// Basic operations
int is_empty(SetIntegers *set) {
    if(!set) {
        return SET_ERROR;
    }

    return set->size == 0;
}

int size(SetIntegers *set) {
    if(!set) {
        return SET_ERROR;
    }

    return set->size;
}

// Operations with elements
int insert(SetIntegers *set, int value) {
    if(!set) {
        return SET_ERROR;
    }

    if(set->size == set->capacity) {
        return SET_ERROR;
    }

    if(belongs(set, value)) {
        return SET_ERROR;
    }

    set->set[set->size++] = value;

    return SET_OK;
}

int remove_value(SetIntegers *set, int value) {
    if(!set) {
        return SET_ERROR;
    }

    int index = -1;

    for(int i = 0; i < set->size; i++) {
        if(set->set[i] == value) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        return SET_ERROR;
    }

    for(int i = index; i < set->size - 1; i++) {
        set->set[i] = set->set[i + 1];
    }

    set->size--;

    return SET_OK;
}

int belongs(SetIntegers *set, int value) {
    if(!set) {
        return SET_ERROR;
    }

    for(int i = 0; i < set->size; i++) {
        if(set->set[i] == value) {
            return 1;
        }
    }

    return 0;
}
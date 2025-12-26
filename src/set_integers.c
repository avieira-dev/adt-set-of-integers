#include "set_integers.h"

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

void display_set(SetIntegers *set) {
    if(!set) {
        printf("\033[31mERROR 'null set'\033[0m\n");
        return;
    }

    printf("{ ");

    for(int i = 0; i < set->size; i++) {
        printf("%d", set->set[i]);

        if(i < set->size - 1) {
            printf(", ");
        }
    }

    printf(" }\n");
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
            return SET_OK;
        }
    }

    return 0;
}

// Operations between sets
SetIntegers *union_sets(SetIntegers *set_a, SetIntegers *set_b) {
    if(!set_a || !set_b) {
        return NULL;
    }

    SetIntegers *result = create_set(set_a->size + set_b->size);

    if(!result) {
        return NULL;
    }

    for(int i = 0; i < set_a->size; i++) {
        insert(result, set_a->set[i]);
    }

    for(int i = 0; i < set_b->size; i++) {
        insert(result, set_b->set[i]);
    }

    return result;
}
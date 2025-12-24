#include "include/set_integers.h"

#include <stdio.h>
#include <stdlib.h>

#define SET_DEFAULT_CAPACITY 8
#define SET_MAX_CAPACITY 100
#define SET_ERROR (-1)

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

    return 1;
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
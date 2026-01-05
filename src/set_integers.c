// ============================================================
// Set of Integers - Implementation
//
// This file contains the private implementation of the
// SetIntegers data structure and its operations.
//
// The internal structure is hidden from the user to ensure
// encapsulation and data integrity.
// ============================================================

#include "set_integers.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
int is_empty(SetIntegers *set, int *out_empty) {
    if(!set || !out_empty) {
        return SET_ERROR;
    }

    *out_empty = (set->size == 0);

    return SET_OK;
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

    int belongs_flag;

    if(belongs(set, value, &belongs_flag) != SET_OK) {
        return SET_ERROR;
    }

    if(belongs_flag) {
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

int belongs(SetIntegers *set, int value, int *out_belongs) {
    if(!set || !out_belongs) {
        return SET_ERROR;
    }

    for(int i = 0; i < set->size; i++) {
        if(set->set[i] == value) {
            *out_belongs = 1;
            return SET_OK;
        }
    }

    *out_belongs = 0;

    return SET_OK;
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

SetIntegers *difference_sets(SetIntegers *set_a, SetIntegers *set_b) {
    if(!set_a || !set_b) {
        return NULL;
    }

    SetIntegers *result = create_set(set_a->size);

    if(!result) {
        return NULL;
    }

    for(int i = 0; i < set_a->size; i++) {
        int belongs_flag;

        if(belongs(set_b, set_a->set[i], &belongs_flag) != SET_OK) {
            destroy(&result);
            return NULL;
        }

        if(!belongs_flag) {
            insert(result, set_a->set[i]);
        }
    }

    return result;
}

SetIntegers *intersection_sets(SetIntegers *set_a, SetIntegers *set_b) {
    if(!set_a || !set_b) {
        return NULL;
    }

    int max_size = set_a->size < set_b->size ? set_a->size : set_b->size;

    SetIntegers *result = create_set(max_size);

    if(!result) {
        return NULL;
    }

    for(int i = 0; i < set_a->size; i++) {
        int belongs_flag;

        if(belongs(set_b, set_a->set[i], &belongs_flag) != SET_OK) {
            destroy(&result);
            return NULL;
        }

        if(belongs_flag) {
            insert(result, set_a->set[i]);
        }
    }

    return result;
}

int equal_sets(SetIntegers *set_a, SetIntegers *set_b) {
    if(!set_a || !set_b) {
        return SET_ERROR;
    }

    if(set_a->size != set_b->size) {
        return 0;
    }

    for(int i = 0; i < set_a->size; i++) {
        int belongs_flag;

        if(belongs(set_b, set_a->set[i], &belongs_flag) != SET_OK) {
            return SET_ERROR;
        }

        if(!belongs_flag) {
            return 0;
        }
    }

    return 1;
}

long long subsets_count(SetIntegers *set) {
    if(!set) {
        return SET_ERROR;
    }

    if(set->size >= 63) {
        return SET_ERROR;
    }

    return 1LL << set->size;
}

// Queries
int minimum_value(SetIntegers *set, int *out_value) {
    if(!set || !out_value) {
        return SET_ERROR;
    }

    if(set->size == 0) {
        return SET_ERROR;
    }

    int min = set->set[0];

    for(int i = 1; i < set->size; i++) {
        if(set->set[i] < min) {
            min = set->set[i];
        }
    }

    *out_value = min;

    return SET_OK;
}

int maximum_value(SetIntegers *set, int *out_value) {
    if(!set || !out_value) {
        return SET_ERROR;
    }

    if(set->size == 0) {
        return SET_ERROR;
    }

    int max = set->set[0];

    for(int i = 1; i < set->size; i++) {
        if(set->set[i] > max) {
            max = set->set[i];
        }
    }

    *out_value = max;

    return SET_OK;
}
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

#define SET_DEFAULT_CAPACITY 8
#define SET_MAX_CAPACITY 100

struct set_integers {
    int size;
    int capacity;
    int *data;
};

/* Lifecycle */

SetIntegers *set_create(int capacity) {
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
    set->data = calloc(capacity, sizeof(int));

    if(!set->data) {
        free(set);
        return NULL;
    }

    return set;
}

int set_destroy(SetIntegers **set) {
    if (!set || !*set) {
        return SET_ERROR;
    }

    free((*set)->data);
    free(*set);
    *set = NULL;

    return SET_OK;
}

/* State queries */

int set_is_empty(const SetIntegers *set, int *out_empty) {
    if(!set || !out_empty) {
        return SET_ERROR;
    }

    *out_empty = (set->size == 0);

    return SET_OK;
}

int set_size(const SetIntegers *set) {
    if(!set) {
        return SET_ERROR;
    }

    return set->size;
}

/* Element operations */

int set_insert(SetIntegers *set, int value) {
    if(!set || set->size == set->capacity) {
        return SET_ERROR;
    }

    int exists;
    if (set_contains(set, value, &exists) != SET_OK || exists) {
        return SET_ERROR;
    }

    set->data[set->size++] = value;
    return SET_OK;
}

int set_remove(SetIntegers *set, int value) {
    if(!set) {
        return SET_ERROR;
    }

    int index = -1;

    for(int i = 0; i < set->size; i++) {
        if(set->data[i] == value) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        return SET_ERROR;
    }

    for(int i = index; i < set->size - 1; i++) {
        set->data[i] = set->data[i + 1];
    }

    set->size--;
    return SET_OK;
}

int set_contains(const SetIntegers *set, int value, int *out_contains) {
    if(!set || !out_contains) {
        return SET_ERROR;
    }

    for(int i = 0; i < set->size; i++) {
        if(set->data[i] == value) {
            *out_contains = 1;
            return SET_OK;
        }
    }

    *out_contains = 0;
    return SET_OK;
}

/* Set operations */

SetIntegers *set_union(const SetIntegers *a, const SetIntegers *b) {
    if(!a || !b) {
        return NULL;
    }

    SetIntegers *result = set_create(a->size + b->size);
    if(!result) {
        return NULL;
    }

    for(int i = 0; i < a->size; i++) {
        set_insert(result, a->data[i]);
    }

    for(int i = 0; i < b->size; i++) {
        set_insert(result, b->data[i]);
    }

    return result;
}

SetIntegers *set_difference(const SetIntegers *a, const SetIntegers *b) {
    if(!a || !b) {
        return NULL;
    }

    SetIntegers *result = set_create(a->size);
    if(!result) {
        return NULL;
    }

    for(int i = 0; i < a->size; i++) {
        int exists;

        set_contains(b, a->data[i], &exists);

        if(!exists) {
            set_insert(result, a->data[i]);
        }
    }

    return result;
}

SetIntegers *set_intersection(const SetIntegers *a, const SetIntegers *b) {
    if(!a || !b) {
        return NULL;
    }

    int max = a->size < b->size ? a->size : b->size;
    SetIntegers *result = set_create(max);

    if(!result) {
        return NULL;
    }

    for(int i = 0; i < a->size; i++) {
        int exists;

        set_contains(b, a->data[i], &exists);

        if(exists) {
            set_insert(result, a->data[i]);
        }
    }

    return result;
}

int set_equals(const SetIntegers *a, const SetIntegers *b) {
    if(!a || !b || a->size != b->size) {
        return 0;
    }

    for(int i = 0; i < a->size; i++) {
        int exists;

        set_contains(b, a->data[i], &exists);

        if(!exists) {
            return 0;
        }
    }

    return 1;
}

/* Mathematical queries */

long long set_subsets_count(const SetIntegers *set) {
    // Limit to prevent overflow in bit shifting (1LL << size)
    if(!set || set->size >= 63) {
        return SET_ERROR;
    }

    return 1LL << set->size;
}

int set_min(const SetIntegers *set, int *out_value) {
    if(!set || !out_value || set->size == 0) {
        return SET_ERROR;
    }

    int min = set->data[0];

    for(int i = 1; i < set->size; i++) {
        if(set->data[i] < min) {
            min = set->data[i];
        }
    }

    *out_value = min;
    return SET_OK;
}

int set_max(const SetIntegers *set, int *out_value) {
    if(!set || !out_value || set->size == 0) {
        return SET_ERROR;
    }

    int max = set->data[0];

    for(int i = 1; i < set->size; i++) {
        if(set->data[i] > max) {
            max = set->data[i];
        }
    }

    *out_value = max;
    return SET_OK;
}

/* Debug */

void set_print(const SetIntegers *set) {
    if(!set) {
        printf("\033[31mERROR 'null set'\033[0m\n");
        return;
    }

    printf("{ ");

    for(int i = 0; i < set->size; i++) {
        printf("%d", set->data[i]);

        if(i < set->size - 1) {
            printf(", ");
        }
    }

    printf(" }\n");
}
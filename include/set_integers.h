#ifndef SET_INTEGERS_H
#define SET_INTEGERS_H

// Data structure
typedef struct set_integers SetIntegers;

// Functions signatures
// Creation and destruction
SetIntegers *create_set(int capacity);
int destroy(SetIntegers **set);

// Basic operations
int is_empty(SetIntegers *set);
int size(SetIntegers *set);

// Operations with elements
int insert(SetIntegers *set, int value);
int remove_value(SetIntegers *set, int value);
int belongs(SetIntegers *set, int value);

// Operations between sets
SetIntegers *union_sets(SetIntegers *set_a, SetIntegers *set_b);
SetIntegers *difference_sets(SetIntegers *set_a, SetIntegers *set_b);
SetIntegers *intersection_sets(SetIntegers *set_a, SetIntegers *set_b);
int equal_sets(SetIntegers *set_a, SetIntegers *set_b);

// Queries
int minimum_value(SetIntegers *set, int *out_value);
int maximum_value(SetIntegers *set, int *out_value);

#endif
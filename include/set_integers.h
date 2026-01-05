#ifndef SET_INTEGERS_H
#define SET_INTEGERS_H

/**
 * @file set_integers.h
 * @brief Integer Set Library
 * This library provides an abstract data type (adt) for a set of integers, 
 * ensuring uniqueness of elements and offering basic set operations.
 */

/** Operation completed successfully. */
#define SET_OK (1)
/** Generic error. */
#define SET_ERROR (-1)

/* ==========================================================================
 * Data structure
 * ========================================================================== */

/**
 * @brief Opaque structure representing a set of integers.
 * Internal fields are hidden from the use to enforce encapsulation.
 */
typedef struct set_integers SetIntegers;

/* ==========================================================================
 * Creation nd destruction
 * ========================================================================== */

/**
 * @brief Creates a new integer set.
 * Allocates memory for a set with the given capacity.
 * If capacity is invalid, a default value is used.
 * @param capacity Initial capacity of the set.
 * @return Pointer to the created set, or NULL on failure.
 */
SetIntegers *create_set(int capacity);

/**
 * @brief Destroys a set and releases its memory.
 * The pointer is set NULL after destruction.
 * @param set Address of the set pointer.
 * @return SET_OK on success, SET_ERROR on failure.
 */
int destroy(SetIntegers **set);

/* ==========================================================================
 * Basic operations
 * ========================================================================== */

/**
 * @brief Checks whether the set is empty.
 * @param set Pointer to the set.
 * @param out_empty Output parameter: 1 if empty, 0 otherwise.
 * @return SET_OK on success, SET_ERROR if the input parameters are invalid
 */
int is_empty(SetIntegers *set, int *out_empty);

/**
 * @brief Returns the number of elements in the set.
 * @param set Pointer to the set.
 * @return Number of elements or SET_ERROR if invalid.
 */
int size(SetIntegers *set);

/**
 * @brief Displays the set elements to stdout.
 * Format: { a, b, c }
 * @param set Pointer to the set.
 */
void display_set(SetIntegers *set);

/* ==========================================================================
 * Operations with elements
 * ========================================================================== */

 /**
 * @brief Inserts a value into the set.
 * The value is only inserted if it does not already exist
 * and the set has available capacity.
 * @param set Pointer to the set.
 * @param value Integer value to insert.
 * @return SET_OK on success, SET_ERROR on failure.
 */
int insert(SetIntegers *set, int value);

/**
 * @brief Removes a value from the set.
 * @param set Pointer to the set.
 * @param value Value to be removed.
 * @return SET_OK on success, SET_ERROR if value is not found.
 */
int remove_value(SetIntegers *set, int value);

/**
 * @brief Checks if a value belongs to the set.
 * @param set Pointer to the set.
 * @param value Value to check.
 * @param out_belongs Output parameter: 1 if belongs, 0 otherwise.
 * @return SET_OK on success, SET_ERROR on failure.
 */
int belongs(SetIntegers *set, int value, int *out_belongs);

/* ==========================================================================
 * Operations between sets
 * ========================================================================== */

/**
 * @brief Returns the union of two sets.
 * @param set_a First set.
 * @param set_b Second set.
 * @return New set containing the union, or NULL on error.
 */
SetIntegers *union_sets(SetIntegers *set_a, SetIntegers *set_b);

/**
 * @brief Returns the difference between two sets (A - B).
 * @param set_a First set.
 * @param set_b Second set.
 * @return New set containing the difference, or NULL on error.
 */
SetIntegers *difference_sets(SetIntegers *set_a, SetIntegers *set_b);

/**
 * @brief Returns the intersection of two sets.
 * @param set_a First set.
 * @param set_b Second set.
 * @return New set containing the intersection, or NULL on error.
 */
SetIntegers *intersection_sets(SetIntegers *set_a, SetIntegers *set_b);

/**
 * @brief Checks if two sets are equal.
 * Two sets are equal if they have the same elements,
 * regardless of order.
 * @param set_a First set.
 * @param set_b Second set.
 * @return 1 if equal, 0 if different, SET_ERROR on failure.
 */
int equal_sets(SetIntegers *set_a, SetIntegers *set_b);

/**
 * @brief Returns the number of subsets of the set
 * @param set Pointer to the set
 * @return Number of subsets or SET_ERROR if invalid
 */

long long subsets_count(SetIntegers *set);

/* ==========================================================================
 * Queries
 * ========================================================================== */

/**
 * @brief Retrieves the minimum value in the set.
 * @param set Pointer to the set.
 * @param out_value Output parameter for the minimum value.
 * @return SET_OK on success, SET_ERROR if the set is empty or invalid.
 */
int minimum_value(SetIntegers *set, int *out_value);

/**
 * @brief Retrieves the maximum value in the set.
 * @param set Pointer to the set.
 * @param out_value Output parameter for the maximum value.
 * @return SET_OK on success, SET_ERROR if the set is empty or invalid.
 */
int maximum_value(SetIntegers *set, int *out_value);

#endif
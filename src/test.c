#include "set_integers.h"

#include <stdio.h>
#include <stdlib.h>

static void separator(void) {
    printf("\n==================================================\n\n");
}

int main(void) {
    printf("=== SET INTEGERS | TEST SUITE ===\n");

    // ----------------------------------------------
    // Creation
    // ----------------------------------------------
    SetIntegers *set_a = create_set(5);
    SetIntegers *set_b = create_set(6);

    if(!set_a || !set_b) {
        printf("\n\033[31mERROR: Failed to create sets\033[0m\n");
        return 1;
    }

    printf("\n\033[32mSets created successfully\033[0m\n");

    separator();

    // ----------------------------------------------
    // Insert elements
    // ----------------------------------------------
    printf("Insert elements into Set A\n");
    insert(set_a, 1);
    insert(set_a, 2);
    insert(set_a, 3);
    insert(set_a, 4);
    insert(set_a, 5);
    display_set(set_a);

    printf("Insert elements into Set B\n");
    insert(set_b, 10);
    insert(set_b, 20);
    insert(set_b, 30);
    insert(set_b, 40);
    insert(set_b, 50);
    insert(set_b, 60);
    display_set(set_b);

    separator();

    // ----------------------------------------------
    // Size and empty check
    // ----------------------------------------------
    int empty_flag;

    is_empty(set_a, &empty_flag);
    printf("Set A is empty? %s\n", empty_flag ? "YES" : "NO");
    printf("Set A size: %d\n", size(set_a));

    long long subsets_a = subsets_count(set_a);

    if(subsets_a != SET_ERROR) {
        printf("Number of subsets of Set A: %lld\n\n", subsets_a);
    } else {
        printf("ERROR calculating subsets of Set A\n\n");
    }

    is_empty(set_b, &empty_flag);
    printf("Set B is empty? %s\n", empty_flag ? "YES" : "NO");
    printf("Set B size: %d\n", size(set_b));

    long long subsets_b = subsets_count(set_b);

    if(subsets_b != SET_ERROR) {
        printf("Number of subsets of Set B: %lld\n", subsets_b);
    } else {
        printf("ERROR calculating subsets of Set B\n");
    }

    separator();

    // ----------------------------------------------
    // Belongs
    // ----------------------------------------------
    int belongs_flag;

    belongs(set_a, 1, &belongs_flag);
    printf("1 belongs to Set A? %s\n", belongs_flag ? "YES" : "NO");

    belongs(set_a, 100, &belongs_flag);
    printf("100 belongs to Set A? %s\n\n", belongs_flag ? "YES" : "NO");

    belongs(set_b, 1, &belongs_flag);
    printf("1 belongs to Set B? %s\n", belongs_flag ? "YES" : "NO");

    belongs(set_b, 100, &belongs_flag);
    printf("100 belongs to Set B? %s\n", belongs_flag ? "YES" : "NO");

    separator();

    // ----------------------------------------------
    // Remove element
    // ----------------------------------------------
    printf("Removing 13 from Set A\n");
    remove_value(set_a, 13);
    display_set(set_a);

    printf("Removing 16 from Set B\n");
    remove_value(set_b, 16);
    display_set(set_b);

    separator();

    // ----------------------------------------------
    // Minimum and maximum
    // ----------------------------------------------
    int min, max;

    if(minimum_value(set_a, &min) == SET_OK) {
        printf("Minimum value in Set A: %d\n", min);
    }

    if(maximum_value(set_a, &max) == SET_OK) {
        printf("Maximum value in Set A: %d\n", max);
    }

    printf("\n");

    if(minimum_value(set_b, &min) == SET_OK) {
        printf("Minimum value in Set B: %d\n", min);
    }

    if(maximum_value(set_b, &max) == SET_OK) {
        printf("Maximum value in Set B: %d\n", max);
    }

    separator();

    // ----------------------------------------------
    // Set Operations
    // ----------------------------------------------
    printf("Union of A and B\n");
    SetIntegers *set_union = union_sets(set_a, set_b);
    display_set(set_union);

    separator();

    printf("Intersection of A and B\n");
    SetIntegers *set_intersection = intersection_sets(set_a, set_b);
    display_set(set_intersection);

    separator();

    printf("Difference A - B\n");
    SetIntegers *set_difference = difference_sets(set_a, set_b);
    display_set(set_difference);

    separator();

    // ----------------------------------------------
    // Equality
    // ----------------------------------------------
    int equal = equal_sets(set_a, set_b);
    printf("Set A equals Set B? %s\n",
           equal == 1 ? "YES" : equal == 0 ? "NO" : "ERROR");

    separator();

    // ----------------------------------------------
    // Cleanup
    // ----------------------------------------------
    destroy(&set_a);
    destroy(&set_b);
    destroy(&set_union);
    destroy(&set_intersection);
    destroy(&set_difference);

    printf("\033[32mAll sets destroyed successfully\033[0m\n");
    printf("\n=== TEST SUITE FINISHED ===\n");

    return 0;
}
#include "set_integers.h"

#include <stdio.h>
#include <stdlib.h>

#define COLOR_RESET   "\033[0m"
#define COLOR_TITLE   "\033[1;34m"
#define COLOR_OK      "\033[1;32m"
#define COLOR_ERR     "\033[1;31m"
#define COLOR_LABEL   "\033[1;36m"

static void banner(const char *title) {
    printf("\n" COLOR_TITLE);
    printf("==================================================\n");
    printf(" %s\n", title);
    printf("==================================================\n" COLOR_RESET);
}

static void section(const char *title) {
    printf("\n" COLOR_LABEL ">> %s\n" COLOR_RESET, title);
}

static void result_ok(const char *msg) {
    printf(COLOR_OK "✔ %s\n" COLOR_RESET, msg);
}

static void result_err(const char *msg) {
    printf(COLOR_ERR "✖ %s\n" COLOR_RESET, msg);
}

int main(void) {
    banner("SET INTEGERS — TEST SUITE");

    section("Creating sets");

    SetIntegers *a = set_create(5);
    SetIntegers *b = set_create(6);

    if(a && b) {
        result_ok("Sets A and B created successfully");
    } else {
        result_err("Failed to create sets");
        return 1;
    }

    section("Inserting elements");

    set_insert(a, 1);
    set_insert(a, 2);
    set_insert(a, 3);
    set_insert(a, 4);
    set_insert(a, 5);

    printf("Set A = ");
    set_print(a);

    set_insert(b, 10);
    set_insert(b, 20);
    set_insert(b, 30);
    set_insert(b, 40);
    set_insert(b, 50);
    set_insert(b, 60);

    printf("Set B = ");
    set_print(b);

    section("Basic queries");

    int empty;
    set_is_empty(a, &empty);
    printf("Set A empty? %s\n", empty ? "YES" : "NO");
    printf("Set A size: %d\n", set_size(a));

    long long subsets = set_subsets_count(a);
    printf("Set A subsets: %lld\n", subsets);

    section("Set operations");

    SetIntegers *u = set_union(a, b);
    printf("Union(A, B) = ");
    set_print(u);

    SetIntegers *i = set_intersection(a, b);
    printf("Intersection(A, B) = ");
    set_print(i);

    SetIntegers *d = set_difference(a, b);
    printf("Difference(A - B) = ");
    set_print(d);

    section("Cleanup");

    set_destroy(&a);
    set_destroy(&b);
    set_destroy(&u);
    set_destroy(&i);
    set_destroy(&d);

    result_ok("All resources released successfully");

    banner("TEST SUITE FINISHED");
    return 0;
}
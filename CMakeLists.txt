cmake_minimum_required(VERSION 3.10)

project(set_integers
    VERSION 1.0
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(set_integers
    src/test.c
    src/set_integers.c
)

target_include_directories(set_integers
    PRIVATE include
)

target_compile_options(set_integers
    PRIVATE -Wall -Wextra -Wpedantic
)
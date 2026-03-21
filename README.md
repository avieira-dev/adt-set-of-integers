# Integer Set ADT (C)

> A minimal and modular integer set ADT in C, focused on clean API design and explicit memory management.

![status](https://img.shields.io/badge/status-active-brightgreen)
![language](https://img.shields.io/badge/language-C-blue)
![build](https://img.shields.io/badge/build-CMake-orange)
![license](https://img.shields.io/badge/license-MIT-blue)

> [!NOTE]  
> Designed as a learning tool and a foundation for future expansion.

## Table of Contents
- [Overview](#overview)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage Example](#usage-example)
- [Compiling and Running](#compiling-and-running)
- [Developer](#developer)
- [License](#license)

## Overview
**Integer Set ADT** is a C library that implements a **custom Abstract Data Type (ADT) for integer sets**, with a strong emphasis on **encapsulation**, **explicit memory management**, and **clean API design**.

It provides core set operations such as creation, insertion, removal, and membership queries, offering a minimal and predictable interface for working with integer collections.

The project is designed to reinforce **low-level data structure modeling** and key software engineering practices in C, including clear separation between interface and implementation, well-defined contracts, and disciplined resource management.

The result is a **lightweight, modular, and reusable ADT**, suitable for learning purposes and as a foundation for future extensions.

## Project Structure

```text
adt-set-of-integers/
├── src/  
│   ├── test.c
│   └── set_integers.c
├── include/ 
│   └── set_integers.h
├── CMakeLists.txt
├── .gitignore
└── README.md
```

## Requirements

- **CMake** (version 3.25 or higher recommended)
- **C compiler** (GCC, Clang or MSVC)

## Installation

### Ubuntu / Debian

```bash
sudo apt update
sudo apt install cmake
cmake --version
```

### MacOS (with Homebrew)

```bash
brew install cmake
cmake --version
```

### Windows

1. Download the installer from the official website: [https://cmake.org/download/](https://cmake.org/download/)

2. Follow the installation wizard and add CMake to the PATH.

3. Check the installation:

```bash
cmake --version
```

## Usage Example

```c
#include <stdio.h>
#include "set_integers.h"

int main(void) {

    // Create a set with initial capacity
    SetIntegers *set = set_create(5);

    if (!set) {
        printf("Failed to create set\n");
        return 1;
    }

    // Insert elements
    set_insert(set, 10);
    set_insert(set, 20);
    set_insert(set, 30);

    // Check membership
    int exists;
    set_contains(set, 20, &exists);
    printf("Contains 20? %s\n", exists ? "YES" : "NO");

    // Print set
    printf("Set = ");
    set_print(set);

    // Cleanup
    set_destroy(&set);

    return 0;
}
```

> [!NOTE]  
> A complete example is available at: **src/test.c**

## Compiling and Running

1. Create a `build` folder at the root of the project and navigate into it.

```bash
mkdir build
cd build
```

2. Generate the build system:

```bash
cmake ..
```

3. Build the project:

```bash
cmake --build .
```

> [!NOTE]  
> On Linux/Mac, you can alternatively run **make** if CMake  
> generated a Makefile.

4. Run the generated binary (assuming it’s `set_integers`):

```bash
./set_integers   # Linux/Mac
set_integers.exe # Windows
```

> [!NOTE]
> **cmake --build .** performs incremental builds — only files that changed  
> are recompiled.

## Developer
**Alexandre Vieira**  
GitHub: [@avieira-dev](https://github.com/avieira-dev)

## License
Distributed under the license [MIT License](LICENSE). See the **LICENSE** file for more details.
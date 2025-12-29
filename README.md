# Abstract Data Type - Set Of Integers

**Project Status:** First stage (part) completed.

## Overview
`Set Integers` is a small C project that implements a **custom set (ADT) for integers**.  
It provides basic operations like:

- Creating a set
- Adding integers
- Removing integers
- Checking membership

The goal is to have a **clean, modular, and reusable ADT**, suitable for learning and future expansion.

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
- **Compiler** C/C++ (GCC, Clang ou MSVC)

## CMake installation

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

## Compiling and Running

1. Create a `build` folder at the root of the project and navigate into it.

```bash
mkdir build
cd build
```

2. Generate the build system::

```bash
cmake ..
```

3. Build the project:

```bash
cmake --build .
```

> On Linux/Mac, you can alternatively run `make` if CMake generated a Makefile.

4. Run the generated binary (assuming it’s `set_integers`):

```bash
./set_integers   # Linux/Mac
set_integers.exe # Windows
```

> Note: `cmake --build .` performs incremental builds — only files that changed are recompiled.

## Observations

- This project is under development.
- Designed as a learning tool and a foundation for future expansion.
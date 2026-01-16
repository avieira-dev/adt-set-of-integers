# Abstract Data Type - Set Of Integers

**Project Status:** Core ADT implemented and validated via test suite.

## Table of Contents
- [Overview](#overview)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [CMake installation](#cmake-installation)
- [Compiling and Running](#compiling-and-running)
- [Observations](#observations)
- [License](#license)

## Overview
`Set Integers` is a C project that implements a **custom Abstract Data Type (ADT) for integer sets**, designed with a strong focus on **encapsulation, explicit memory management**, and clean **API design**.

The project provides core set operations such as creation, insertion, removal, and membership queries, serving as a practical exercise in **data structure modeling at a low level**.

Beyond functionality, the main goal is to practice and demonstrate **fundamental software engineering principles in C**, including separation between interface and implementation, well-defined contracts, and disciplined resource management.

The result is a **clean, modular, and reusable ADT**, suitable both for learning purposes and as a foundation for future extensions.

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

## License
[MIT License](LICENSE)
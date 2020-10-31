# An implementation of Primitive Recursive Arithmetic (PRA) in C++ #

This repository contains an implementation of PRA in C++, written as part of a level 4 university mathematics project on Go&#x308;dels Incompleteness Theorem.

## Building ##
### Build Requirements ###
- A C++14 compiler.
- The CLN - Class Library for Numbers as distributed under the GNU General Public License, version 2. [link](https://www.ginac.de/CLN/)
- The Boost.Mp11 C++11 metaprogramming library as distributed under the Boost Software License, version 1.0. [link](https://www.boost.org/doc/libs/develop/libs/mp11/doc/html/mp11.html)
### Build Options ###
The RECURSIVE flag implements PRA using primitive recursion, if not set primitive recursion is implemented using an iterative method. If set, see Notes.
### Build Instructions ###
Using CMake is preferred.
A sample CMakeLists.txt file is included in the root of the directory.
After setting the preffered C++14 compiler and library locations the project may be built from the projects root directory with:
```
mkdir build
cd build
cmake ..
make
```
By default the resulting executable is named godel.
## Notes ##
If the RECURSIVE flag is set, the stack depth of arithmetic operations can become larger than the available system memory or can be caught by an out of memory killer in the environment.

Documentation is not included, as this was part of the write-up for a project which may be run again.
## Listing ##
. \
├── include \
│   ├── arithmetic.h \
│   ├── arithmetic.tpp \
│   ├── examples_eq.h \
│   ├── examples.h \
│   ├── primitive.h \
│   ├── primitive.tpp \
│   └── utility.h \
├── src \
│   ├── examples.cpp \
│   ├── main.cpp \
│   └── utility.cpp \
├── CMakeLists.txt \
├── LICENSE \
└── README.md 

2 directories, 12 files

## License ##
This code is distributed under the 3-clause BSD license.
See LICENSE for more details.

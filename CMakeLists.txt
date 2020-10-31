#
#Sample CMakeLists.txt
#Project: An implementation of PRA in C++
#
#Tested on a NetBSD machine with pkgsrc 2020Q4 userland
# and Linux machine with a CRUX linux 3.5 userland
# using packages cln, cmake and clang
#
cmake_minimum_required(VERSION 3.15.3)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
#set(CMAKE_CXX_FLAGS "-fpermissive -std=c++2a -O3 -DRECURSIVE" CACHE STRING "compile flags" FORCE)
set(CMAKE_CXX_FLAGS "-fpermissive -std=c++2a -O3" CACHE STRING "compile flags" FORCE)
set(CMAKE_EXE_LINKER_FLAGS "/usr/lib/libcln.a")
project(Godel)
include_directories(include /usr/pkg/include)
set(target_sources
    utility.cpp
    examples.cpp
    main.cpp
)
list(TRANSFORM target_sources PREPEND "src/")
add_executable(godel ${target_sources})
target_link_libraries(godel "/usr/lib/libcln.so")

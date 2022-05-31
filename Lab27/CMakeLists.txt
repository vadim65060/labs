cmake_minimum_required(VERSION 3.21)
project(Lab27 C)

set(CMAKE_C_STANDARD 23)

#include_directories("C:/MinGW/mingw32/include")
#link_directories("C:/MinGW/mingw32/lib")

add_executable(Lab27 main.c graph.c graph.h rbt.c rbt.h)
target_link_libraries (Lab27 "libgdi32.a" "libopenbgi.a")




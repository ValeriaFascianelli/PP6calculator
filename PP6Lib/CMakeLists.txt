# CMake script for pp6 library

# - Add the PP6Lib library
add_library(pp6lib SHARED Math.hpp Math.cpp operation.cpp operation.hpp Physics.hpp Physics.cpp EnSigma.hpp EnSigma.cpp)

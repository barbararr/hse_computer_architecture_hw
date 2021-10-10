cmake_minimum_required(VERSION 3.20)
project(abc)

set(CMAKE_CXX_STANDARD 17)

add_executable(abc main.cpp container.h container.cpp matrix.h matrix.cpp twoDimensionalArray.h twoDimensionalArray.cpp diagonalMatrix.h diagonalMatrix.cpp lowerTriangularMatrix.h lowerTriangularMatrix.cpp random.h)

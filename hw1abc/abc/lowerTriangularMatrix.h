#ifndef ABC_LOWERTRIANGULARMATRIX_H
#define ABC_LOWERTRIANGULARMATRIX_H

//------------------------------------------------------------------------------
// lowerTriangularMatrix.h - содержит описание нижней треугольной матрицы и её интерфейса.
//------------------------------------------------------------------------------

#include "random.h"
#include <stdio.h>

//------------------------------------------------------------------------------
// Нижняя треугольная матрица.
struct lowerTriangularMatrix {
    int dimension;
    double* ltmElements;
};

// Ввод параметров нижней треугольной матрицы из файла.
void In(lowerTriangularMatrix &ltm, FILE* file);

// Случайный ввод параметров треугольника.
void InRandom(lowerTriangularMatrix &ltm);

// Вывод параметров нижней треугольной матрицы в файл.
void Out(lowerTriangularMatrix &ltm, FILE* file);

// Вычисление среднего арифметического нижней треугольной матрицы.
double ArithmeticMean(lowerTriangularMatrix &ltm);

#endif //ABC_LOWERTRIANGULARMATRIX_H
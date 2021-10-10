#ifndef ABC_DIAGONALMATRIX_H
#define ABC_DIAGONALMATRIX_H

//------------------------------------------------------------------------------
// diagonalMatrix.h - содержит описание диагональной матрицы и её интерфейса.
//------------------------------------------------------------------------------

#include "random.h"
#include <stdexcept>

//------------------------------------------------------------------------------
// Диагональная матрица.
struct diagonalMatrix {
    int dimension;
    double* dmElements;
};

// Ввод параметров диагональной матрицы из файла.
void In(diagonalMatrix &dm, FILE* file);

// Случайный ввод параметров треугольника.
void InRandom(diagonalMatrix &dm);

// Вывод параметров диагональной матрицы в файл.
void Out(diagonalMatrix &dm, FILE* file);

// Вычисление среднего арифметического диагональной матрицы.
double ArithmeticMean(diagonalMatrix &dm);


#endif //ABC_DIAGONALMATRIX_H
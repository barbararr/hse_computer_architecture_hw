#ifndef ABC_MATRIX_H
#define ABC_MATRIX_H

//------------------------------------------------------------------------------
// matrix.h - содержит описание обобщающей матрицы.
//------------------------------------------------------------------------------

#include "twoDimensionalArray.h"
#include "diagonalMatrix.h"
#include "lowerTriangularMatrix.h"
#include <stdexcept>

//------------------------------------------------------------------------------
// Структура, обобщающая все имеющиеся матрицы.
struct matrix {
    // Значения ключей для каждой из матриц.
    enum key {TWODIMARRAY, DIAGMATRIX, LOWERTRIANGMATRIX};
    // Ключ.
    key k;
    // Используемые альтернативы.
    union {
        twoDimensionalArray tda;
        diagonalMatrix dm;
        lowerTriangularMatrix ltm;
    };
};

// Ввод обобщающей матрицы.
matrix* In(FILE* file);

// Случайный ввод обобщающей матрицы.
matrix* InRandom();

// Вывод обобщающей матрицы.
void Out(matrix &m, FILE* file);

// Вычисление среднего арифметического обобщенной матрицы.
double ArithmeticMean(matrix &m);

#endif //ABC_MATRIX_H
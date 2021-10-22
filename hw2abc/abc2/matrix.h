#ifndef ABC2_MATRIX_H
#define ABC2_MATRIX_H

//------------------------------------------------------------------------------
// matrix.h - содержит описание обобщающей матрицы.
//------------------------------------------------------------------------------

//#include "twoDimensionalArray.h"
//#include "diagonalMatrix.h"
//#include "lowerTriangularMatrix.h"
#include <stdexcept>
#include "random.h"

//------------------------------------------------------------------------------
// Структура, обобщающая все имеющиеся матрицы.
class Matrix {
protected:
    static Random rnd;
public:
    virtual ~Matrix() {};
    // Ввод обобщающей матрицы.
    static Matrix *StaticIn(FILE* file);
    // Ввод обобщающей матрицы.
    virtual  void In(FILE* file) = 0;
    // Случайный ввод обобщающей матрицы.
    static Matrix *StaticInRandom();
    // Случайный ввод обобщающей матрицы.
    virtual void InRandom() = 0;
    // Вывод обобщающей матрицы.
    virtual void Out(FILE* file) = 0;
    // Вычисление среднего арифметического обобщенной матрицы.
    virtual double ArithmeticMean() = 0;
};

#endif //ABC2_MATRIX_H
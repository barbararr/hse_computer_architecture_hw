#ifndef ABC2_DIAGONALMATRIX_H
#define ABC2_DIAGONALMATRIX_H

//------------------------------------------------------------------------------
// diagonalMatrix.h - содержит описание диагональной матрицы и её интерфейса.
//------------------------------------------------------------------------------

#include "random.h"
#include <stdexcept>
#include "matrix.h"

//------------------------------------------------------------------------------
// Диагональная матрица.

class DiagonalMatrix: public Matrix {
public:
    virtual ~DiagonalMatrix() {}
    // Ввод параметров диагональной матрицы из файла.
    virtual void In(FILE* file);
    // Случайный ввод параметров диагональной матрицы .
    virtual void InRandom();
    // Вывод параметров диагональной матрицы в файл.
    virtual void Out(FILE* file);
    // Вычисление среднего арифметического диагональной матрицы.
    virtual double ArithmeticMean();
private:
    int dimension;
    double* dmElements;
};

#endif //ABC2_DIAGONALMATRIX_H
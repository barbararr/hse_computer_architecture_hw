#ifndef ABC2_LOWERTRIANGULARMATRIX_H
#define ABC2_LOWERTRIANGULARMATRIX_H

//------------------------------------------------------------------------------
// lowerTriangularMatrix.h - содержит описание нижней треугольной матрицы и её интерфейса.
//------------------------------------------------------------------------------

#include "random.h"
#include <stdio.h>
#include "matrix.h"

//------------------------------------------------------------------------------
// Нижняя треугольная матрица.
class LowerTriangularMatrix: public Matrix {
public:
    virtual ~LowerTriangularMatrix() {}
    // Ввод параметров нижней треугольной матрицы из файла.
    virtual void In(FILE* file);
    // Случайный ввод параметров нижней треугольной матрицы.
    virtual void InRandom();
    // Вывод параметров нижней треугольной матрицы в файл.
    virtual void Out(FILE* file);
    // Вычисление среднего арифметического нижней треугольной матрицы.
    virtual double ArithmeticMean();
private:
    int dimension;
    double* ltmElements;
};

#endif //ABC2_LOWERTRIANGULARMATRIX_H
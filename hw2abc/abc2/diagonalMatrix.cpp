//------------------------------------------------------------------------------
// diagonalMatrix.cpp - содержит функции обработки диагональной матрицы
//-----------------------------------------------------------------------------

#include "diagonalMatrix.h"
#include <stdexcept>

//------------------------------------------------------------------------------
// Ввод параметров диагональной матрицы из потока.
void DiagonalMatrix::In(FILE* file) {
    fscanf(file, "%d", &dimension);
    dmElements = new double [dimension];
    for (int i = 0; i < dimension; ++i) {
        fscanf(file, "%lf", &dmElements[i]);
    }
}

// Случайный ввод параметров диагональной матрицы.
void DiagonalMatrix::InRandom() {
    dimension = Matrix::rnd.Get();
    dmElements = new double [dimension];
    for (int i = 0; i < dimension; ++i) {
        dmElements[i] = Matrix::rnd.GetDouble();
    }
}

//------------------------------------------------------------------------------
// Вывод параметров диагональной матрицы в поток.
void DiagonalMatrix::Out(FILE* file) {
    fprintf(file, "It is diagonal matrix: dimension = %d. Arithmetic mean = %.2f", dimension, ArithmeticMean());
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического диагональной матрицы.
double DiagonalMatrix::ArithmeticMean() {
    double sum = 0.0;
    for (int i = 0; i < dimension; ++i) {
        sum += dmElements[i];
    }
    return double(sum / (dimension * dimension));
}

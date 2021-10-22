//------------------------------------------------------------------------------
// twoDimensionalArray.cpp - содержит функции обработки обычного двумерного массива
//-----------------------------------------------------------------------------

#include "twoDimensionalArray.h"
#include <stdexcept>

//------------------------------------------------------------------------------
// Ввод параметров обычного двумерного массива из потока.
void TwoDimensionalArray::In(FILE* file) {
    fscanf(file, "%d", &dimension);
    tdaElements = new double* [dimension];
    for (int i = 0; i < dimension; ++i) {
        tdaElements[i] = new double[dimension];
        for (int j = 0; j < dimension; ++j) {
            fscanf(file, "%lf", &tdaElements[i][j]);
        }
    }
}

// Случайный ввод параметров обычного двумерного массива.
void TwoDimensionalArray::InRandom() {
    dimension = Matrix::rnd.Get();
    tdaElements = new double* [dimension];
    for (int i = 0; i < dimension; ++i) {
        tdaElements[i] = new double [dimension];
        for (int j = 0; j < dimension; ++j) {
            tdaElements[i][j] = Matrix::rnd.GetDouble();
        }
    }
}

//------------------------------------------------------------------------------
// Вывод параметров обычного двумерного массива в поток.
void TwoDimensionalArray::Out(FILE* file) {
    fprintf(file, "It is two dimensional array: dimension = %d. Arithmetic mean = %.2f", dimension, ArithmeticMean());
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического обычного двумерного массива.
double TwoDimensionalArray::ArithmeticMean() {
    double sum = 0.0;
    for (int i = 0; i < dimension; ++i) {
        for (int j = 0; j < dimension; ++j) {
            sum += tdaElements[i][j];
        }
    }
    return double(sum / (dimension * dimension));
}
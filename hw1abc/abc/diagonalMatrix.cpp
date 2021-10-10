//------------------------------------------------------------------------------
// diagonalMatrix.cpp - содержит функции обработки диагональной матрицы
//-----------------------------------------------------------------------------

#include "diagonalMatrix.h"
#include <stdexcept>

//------------------------------------------------------------------------------
// Ввод параметров диагональной матрицы из потока.
void In(diagonalMatrix &dm, FILE* file) {
    fscanf(file, "%d", &dm.dimension);
    dm.dmElements = new double [dm.dimension];
    for (int i = 0; i < dm.dimension; ++i) {
        fscanf(file, "%lf", &dm.dmElements[i]);
    }
}

// Случайный ввод параметров диагональной матрицы.
void InRandom(diagonalMatrix &dm) {
    dm.dimension = Random();
    dm.dmElements = new double [dm.dimension];
    for (int i = 0; i < dm.dimension; ++i) {
        dm.dmElements[i] = RandomDouble();
    }
}

//------------------------------------------------------------------------------
// Вывод параметров диагональной матрицы в поток.
void Out(diagonalMatrix &dm, FILE* file) {
    fprintf(file, "It is diagonal matrix: dimension = %d. Arithmetic mean = %.2f", dm.dimension, ArithmeticMean(dm));
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического диагональной матрицы.
double ArithmeticMean(diagonalMatrix &dm) {
    double sum = 0.0;
    for (int i = 0; i < dm.dimension; ++i) {
        sum += dm.dmElements[i];
    }
    return double(sum / (dm.dimension * dm.dimension));
}
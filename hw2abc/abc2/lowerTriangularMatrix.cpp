//------------------------------------------------------------------------------
// lowerTriangularMatrix.cpp - содержит функции обработки нижней треугольной матрицы
//-----------------------------------------------------------------------------

#include "lowerTriangularMatrix.h"
#include <stdexcept>

//------------------------------------------------------------------------------
// Ввод параметров нижней треугольной матрицы из потока.
void LowerTriangularMatrix::In(FILE* file) {
    fscanf(file, "%d", &dimension);
    ltmElements = new double [(dimension*(dimension + 1))/2];
    for (int i = 0; i < (dimension * (dimension + 1)) / 2; ++i) {
        fscanf(file, "%lf", &ltmElements[i]);
    }
}

// Случайный ввод параметров нижней треугольной матрицы.
void LowerTriangularMatrix::InRandom() {
    dimension = Matrix::rnd.Get();
    ltmElements = new double [(dimension * (dimension + 1)) / 2];
    for (int i = 0; i < (dimension * (dimension + 1)) / 2; ++i) {
        ltmElements[i] = Matrix::rnd.GetDouble();
    }
}

//------------------------------------------------------------------------------
// Вывод параметров нижней треугольной матрицы в поток.
void LowerTriangularMatrix::Out(FILE* file) {
    fprintf(file,"It is lower triangular matrix: dimension = %d. Arithmetic mean = %.2f", dimension, ArithmeticMean());
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического нижней треугольной матрицы.
double LowerTriangularMatrix::ArithmeticMean() {
    double sum = 0.0;
    for (int i = 0; i < (dimension * (dimension + 1)) / 2; ++i) {
        sum += ltmElements[i];
    }
    return double(sum / (dimension * dimension));
}
//------------------------------------------------------------------------------
// lowerTriangularMatrix.cpp - содержит функции обработки нижней треугольной матрицы
//-----------------------------------------------------------------------------

#include "lowerTriangularMatrix.h"
#include <stdexcept>

//------------------------------------------------------------------------------
// Ввод параметров нижней треугольной матрицы из потока.
void In(lowerTriangularMatrix &ltm, FILE* file) {
    fscanf(file, "%d", &ltm.dimension);
    ltm.ltmElements = new double [(ltm.dimension*(ltm.dimension + 1))/2];
    for (int i = 0; i < (ltm.dimension * (ltm.dimension + 1)) / 2; ++i) {
        fscanf(file, "%lf", &ltm.ltmElements[i]);
    }
}

// Случайный ввод параметров нижней треугольной матрицы.
void InRandom(lowerTriangularMatrix &ltm) {
    ltm.dimension = Random();
    ltm.ltmElements = new double [(ltm.dimension * (ltm.dimension + 1)) / 2];
    for (int i = 0; i < (ltm.dimension * (ltm.dimension + 1)) / 2; ++i) {
        ltm.ltmElements[i] = RandomDouble();
    }
}

//------------------------------------------------------------------------------
// Вывод параметров нижней треугольной матрицы в поток.
void Out(lowerTriangularMatrix &ltm, FILE* file) {
    fprintf(file,"It is lower triangular matrix: dimension = %d. Arithmetic mean = %.2f", ltm.dimension, ArithmeticMean(ltm));
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического нижней треугольной матрицы.
double ArithmeticMean(lowerTriangularMatrix &ltm) {
    double sum = 0.0;
    for (int i = 0; i < (ltm.dimension * (ltm.dimension + 1)) / 2; ++i) {
        sum += ltm.ltmElements[i];
    }
    return double(sum / (ltm.dimension * ltm.dimension));
}
//------------------------------------------------------------------------------
// twoDimensionalArray.cpp - содержит функции обработки обычного двумерного массива
//-----------------------------------------------------------------------------

#include "twoDimensionalArray.h"
#include <stdexcept>

//------------------------------------------------------------------------------
// Ввод параметров обычного двумерного массива из потока.
void In(twoDimensionalArray &tda, FILE* file) {
    fscanf(file, "%d", &tda.dimension);
    tda.tdaElements = new double* [tda.dimension];
    for (int i = 0; i < tda.dimension; ++i) {
        tda.tdaElements[i] = new double[tda.dimension];
        for (int j = 0; j < tda.dimension; ++j) {
            fscanf(file, "%lf", &tda.tdaElements[i][j]);
        }
    }
}

// Случайный ввод параметров обычного двумерного массива.
void InRandom(twoDimensionalArray &tda) {
    tda.dimension = Random();
    tda.tdaElements = new double* [tda.dimension];
    for (int i = 0; i < tda.dimension; ++i) {
        tda.tdaElements[i] = new double [tda.dimension];
        for (int j = 0; j < tda.dimension; ++j) {
            tda.tdaElements[i][j] = RandomDouble();
        }
    }
}

//------------------------------------------------------------------------------
// Вывод параметров обычного двумерного массива в поток.
void Out(twoDimensionalArray &tda, FILE* file) {
    fprintf(file, "It is two dimensional array: dimension = %d. Arithmetic mean = %.2f", tda.dimension, ArithmeticMean(tda));
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического обычного двумерного массива.
double ArithmeticMean(twoDimensionalArray &tda) {
    double sum = 0.0;
    for (int i = 0; i < tda.dimension; ++i) {
        for (int j = 0; j < tda.dimension; ++j) {
            sum += tda.tdaElements[i][j];
        }
    }
    return double(sum / (tda.dimension * tda.dimension));
}
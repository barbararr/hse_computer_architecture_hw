#ifndef ABC_TWODIMENSIONALARRAY_H
#define ABC_TWODIMENSIONALARRAY_H

//------------------------------------------------------------------------------
// twoDimensionalArray.h - содержит описание обычного двумерного массива и его интерфейса.
//------------------------------------------------------------------------------

#include "random.h"
#include <stdexcept>

//------------------------------------------------------------------------------
// Обычный двумерный массив.
struct twoDimensionalArray {
    int dimension;
    double **tdaElements;
};

// Ввод параметров обычного двумерного массива  из файла.
void In(twoDimensionalArray &tda, FILE* file);

// Случайный ввод параметров треугольника.
void InRandom(twoDimensionalArray &tda);

// Вывод параметров обычного двумерного массива в файл.
void Out(twoDimensionalArray &tda, FILE* file);

// Вычисление среднего арифметического обычного двумерного массива.
double ArithmeticMean(twoDimensionalArray &tda);

#endif //ABC_TWODIMENSIONALARRAY_H
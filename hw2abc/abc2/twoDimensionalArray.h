#ifndef ABC2_TWODIMENSIONALARRAY_H
#define ABC2_TWODIMENSIONALARRAY_H

//------------------------------------------------------------------------------
// twoDimensionalArray.h - содержит описание обычного двумерного массива и его интерфейса.
//------------------------------------------------------------------------------

#include "random.h"
#include <stdexcept>
#include "matrix.h"

//------------------------------------------------------------------------------
// Обычный двумерный массив.
class TwoDimensionalArray: public Matrix {
public:
    virtual ~TwoDimensionalArray() {}
    // Ввод параметров обычного двумерного массива  из файла.
    virtual void In(FILE* file);
    // Случайный ввод параметров обычного двумерного массива.
    virtual void InRandom();
    // Вывод параметров обычного двумерного массива в файл.
    virtual void Out(FILE* file);
    // Вычисление среднего арифметического обычного двумерного массива.
    virtual double ArithmeticMean();
private:
    int dimension;
    double **tdaElements;
};

#endif //ABC2_TWODIMENSIONALARRAY_H
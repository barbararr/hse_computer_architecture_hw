//------------------------------------------------------------------------------
// matrix.cpp - содержит процедуры связанные с обработкой обобщенной матрицы
// и создания произвольной матрицы
//------------------------------------------------------------------------------

#include "matrix.h"
#include <stdio.h>
#include "twoDimensionalArray.h"
#include "lowerTriangularMatrix.h"
#include "diagonalMatrix.h"

//------------------------------------------------------------------------------
Random Matrix::rnd(1, 20);

//------------------------------------------------------------------------------
// Ввод обобщающей матрицы.
Matrix* Matrix::StaticIn(FILE *file) {
    int k = 0;
    Matrix* m;
    fscanf(file, "%d", &k);
    switch(k) {
        case 1:
            m = new TwoDimensionalArray;
            break;
        case 2:
            m = new DiagonalMatrix;
            break;
        case 3:
            m = new LowerTriangularMatrix;
            break;
        default:
            return nullptr;
    }
    m->In(file);
    return m;
}

// Случайный ввод обобщающей матрицы.
Matrix* Matrix::StaticInRandom() {
    int k = rand() % 3 + 1;
    Matrix* m;
    switch(k) {
        case 1:
            m = new TwoDimensionalArray;
            break;
        case 2:
            m = new DiagonalMatrix;
            break;
        case 3:
            m = new LowerTriangularMatrix;
            break;
        default:
            return 0;
    }
    m->InRandom();
    return m;
}
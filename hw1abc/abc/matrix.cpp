//------------------------------------------------------------------------------
// matrix.cpp - содержит процедуры связанные с обработкой обобщенной матрицы
// и создания произвольной матрицы
//------------------------------------------------------------------------------

#include "matrix.h"
#include <stdio.h>

//------------------------------------------------------------------------------
// Ввод обобщающей матрицы.
matrix* In(FILE *file) {
    int k = 0;
    matrix* m;
    fscanf(file, "%d", &k);
    switch(k) {
        case 1:
            m = new matrix;
            m->k = matrix::TWODIMARRAY;
            In(m->tda, file);
            return m;
        case 2:
            m = new matrix;
            m->k = matrix::DIAGMATRIX;
            In(m->dm, file);
            return m;
        case 3:
            m = new matrix;
            m->k = matrix::LOWERTRIANGMATRIX;
            In(m->ltm, file);
            return m;
        default:
            return nullptr;
    }
}

// Случайный ввод обобщающей матрицы.
matrix* InRandom() {
    int k = rand() % 3 + 1;
    matrix* m;
    switch(k) {
        case 1:
            m = new matrix;
            m->k = matrix::TWODIMARRAY;
            InRandom(m->tda);
            return m;
        case 2:
            m = new matrix;
            m->k = matrix::DIAGMATRIX;
            InRandom(m->dm);
            return m;
        case 3:
            m = new matrix;
            m->k = matrix::LOWERTRIANGMATRIX;
            InRandom(m->ltm);
            return m;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод обобщающей матрицы.
void Out(matrix& m, FILE *file) {
    switch(m.k) {
        case matrix::TWODIMARRAY:
            Out(m.tda, file);
            break;
        case matrix::DIAGMATRIX:
            Out(m.dm, file);
            break;
        case matrix::LOWERTRIANGMATRIX:
            Out(m.ltm, file);
            break;
        default:
            fprintf(file, "%s", "Incorrect matrix!");
    }
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического матрицы.
double ArithmeticMean(matrix& m) {
    switch (m.k) {
        case matrix::TWODIMARRAY:
            return ArithmeticMean(m.tda);
        case matrix::DIAGMATRIX:
            return ArithmeticMean(m.dm);
        case matrix::LOWERTRIANGMATRIX:
            return ArithmeticMean(m.ltm);
        default:
            return 0;
    }
}
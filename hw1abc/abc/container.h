#ifndef ABC_CONTAINER_H
#define ABC_CONTAINER_H

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "matrix.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива.
struct container {
    enum {max_len = 10000}; // максимальная длина
    int len; // текущая длина
    matrix* cont[max_len];
};

// Инициализация контейнера.
void Init(container &c);

// Очистка контейнера от элементов (освобождение памяти).
void Clear(container &c);

// Ввод содержимого контейнера из указанного потока.
void In(container &c, FILE *file);

// Случайный ввод содержимого контейнера.
void InRandom(container &c, int size);

// Вывод содержимого контейнера в указанный поток.
void Out(container &c, FILE *file);

// Вычисление среднего арифметического средних арифметических всех матриц в контейнере.
double ArithmeticMeanAll(container &c);

void ShellSorting(container &c);

#endif //ABC_CONTAINER_H
#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера.
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти).
void Clear(container &c) {
    for (int i = 0; i < c.len; ++i) {
        delete c.cont[i];
    }
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока.
void In(container &c, FILE *file) {
    while(!feof(file)) {
        if((c.cont[c.len] = In(file)) !=  0) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера.
void InRandom(container &c, int size) {
    while(c.len < size) {
        if((c.cont[c.len] = InRandom()) != 0) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток.
void Out(container &c, FILE *file) {
    fprintf(file, "Container contains %d elements.\n", c.len);
    for (int i = 0; i < c.len; i++) {
        fprintf(file, "%d: ", i);
        Out(*c.cont[i], file);
        fprintf(file, "%s", "\n");
    }
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического средних арифметических всех матриц в контейнере.
double ArithmeticMeanAll(container &c) {
    double sum = 0.0;
    for(int i = 0; i < c.len; i++) {
        sum += ArithmeticMean(*c.cont[i]);
    }
    return sum;
}

//------------------------------------------------------------------------------
// Сортировка контейнера по убыванию методом Шелла.
void ShellSorting(container &c){
    int step = c.len / 2;
    matrix* temp;
    while (step > 0) {
        for (int i = 0; i < (c.len - step); ++i) {
            int j = i;
            while (j >= 0 && ArithmeticMean(*c.cont[j]) < ArithmeticMean(*c.cont[j + step])) {
                temp = c.cont[j];
                c.cont[j] = c.cont[j + step];
                c.cont[j + step] = temp;
                j -= step;
            }
        }
        step /= 2;
    }
}
#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера.
Container::Container(): len{0} { }

//------------------------------------------------------------------------------
// Деструктор контейнера.
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти).
void Container::Clear() {
    for (int i = 0; i < len; ++i) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока.
void Container::In(FILE *file) {
    while(!feof(file)) {
        if((storage[len] = Matrix::StaticIn(file)) !=  0) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера.
void Container::InRandom(int size) {
    while(len < size) {
        if((storage[len] = Matrix::StaticInRandom()) != 0) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток.
void Container::Out(FILE *file) {
    fprintf(file, "Container contains %d elements.\n", len);
    for (int i = 0; i < len; i++) {
        fprintf(file, "%d: ", i);
        storage[i]->Out(file);
        fprintf(file, "%s", "\n");
    }
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического средних арифметических всех матриц в контейнере.
double Container::ArithmeticMeanAll() {
    double sum = 0.0;
    for(int i = 0; i < len; i++) {
        sum += storage[i]->ArithmeticMean();
    }
    return sum;
}

//------------------------------------------------------------------------------
// Сортировка контейнера по убыванию методом Шелла.
void Container::ShellSorting(){
    int step = len / 2;
    Matrix* temp;
    while (step > 0) {
        for (int i = 0; i < (len - step); ++i) {
            int j = i;
            while (j >= 0 && storage[j]->ArithmeticMean() < storage[j + step]->ArithmeticMean()) {
                temp = storage[j];
                storage[j] = storage[j + step];
                storage[j + step] = temp;
                j -= step;
            }
        }
        step /= 2;
    }
}
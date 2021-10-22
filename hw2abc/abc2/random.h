#ifndef ABC2_RANDOM_H
#define ABC2_RANDOM_H

#include <cstdlib>
#include <ctime>
class Random {
public:
    Random(int f, int l) {
        if(f <= l) {
            first = f;
            last = l;
        } else {
            first = l;
            last = f;
        }
        // Cистемные часы в качестве инициализатора.
        srand(static_cast<unsigned int>(time(0)));
    }
    // Генерация случайного числа в заданном диапазоне.
    int Get() {
        return rand() % (last - first + 1) + first;
    }
    // Генерация случайного вещественного числа.
    double GetDouble() {
        return (rand() % (1000)) / 1000.0 + 1;
    }
private:
    int first;
    int last;
};

#endif //ABC2_RANDOM_H
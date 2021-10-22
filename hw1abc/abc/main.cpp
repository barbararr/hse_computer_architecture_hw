#include <stdlib.h> // Для функции rand().
#include <time.h>   // Для функции time().
#include <string.h>
#include <stdio.h>

#include "container.h"

// Вывод сообщения об ошибке.
void errMessage() {
    printf("incorrect command line!\n");
    printf("  Waited:\n");
    printf("     command -f infile outfile\n");
    printf("  Or:\n");
    printf("     command -n number outfile\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if(argc != 4) {
        errMessage();
        return 1;
    }
    printf("Start\n");
    clock_t start, end;
    start = clock();
    container cont;
    Init(cont);

    // Ввод элементов из файла.
    if(!strcmp(argv[1], "-f")) {
        FILE *fileInput = fopen(argv[2], "r");
        In(cont, fileInput);
        fclose(fileInput);
    } else {
        // Генерация рандомных элементов.
        if (!strcmp(argv[1], "-n")) {
            int size = atoi(argv[2]);
            if ((size < 1) || (size > 10000)) {
                printf("incorrect number of matrixes = %d. Set 0 < number <= 10000\n", size);
                return 3;
            } else {
                srand((unsigned int)(time(0)));
                InRandom(cont, size);
            }
        } else {
            errMessage();
            return 2;
        }
    }
    // Вывод элементов контейнера.
    FILE *fileOutput;
    fileOutput = fopen(argv[3], "w");
    Out(cont, fileOutput);

    // Сортировка контейнера.
    ShellSorting(cont);
    // Вывод отсортированных элементов контейнера.
    fprintf(fileOutput, "%s", "\n\nSorted container:\n");
    Out(cont, fileOutput);
    fclose(fileOutput);
    // Очистка контейнера.
    Clear(cont);

    // Остановка времени.
    end = clock();
    double all_time = (double)(end - start) / CLOCKS_PER_SEC;
    // Вывод времени.
    printf("Total time: %lf seconds\n", all_time);
    printf("Stop\n");
    return 0;
}

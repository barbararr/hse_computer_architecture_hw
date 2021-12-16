#include <iostream>
#include <vector>
#include <thread>
#include <string>

//-------------------------------------------------------
// Количество задач.
int tasksNumber;
// Лес.
std::vector<int> forest;

//-------------------------------------------------------
// Ввод и проверка размера леса.
int EnteringForestLength() {
    int forestLength = -1;
    std::cout << "Enter the number of trees (between 30 and 2000000000):\n";
    try {
        std::cin >> forestLength;
        if (forestLength < 30 || forestLength > 200000000) {
            std::cout << "\nWrong number of trees.\n";
            return -1;
        }
    } catch (std::exception&) {
        std::cout << "\nWrong number of trees.\n";
        return -1;
    }
    return forestLength;
}

//-------------------------------------------------------
// Задание вектора леса, где Винни Пух помечен единицей.
void FillingTheForest(int forestLength) {
    int winnieIndex = rand() % forestLength;
    for (int i = 0; i < forestLength; ++i) {
        if (i == winnieIndex) {
            forest.push_back(1);
        } else {
            forest.push_back(0);
        }
    }
    // Подсчитываем число задач для потоков.
    if (forestLength % 10 != 0) {
        tasksNumber = (forestLength / 10) + 1;
    } else {
        tasksNumber = (forestLength / 10);
    }
}

//-------------------------------------------------------
// Поиск Винни Пуха в лесу.
void FindingWinnieThePooh(int startingIndex, int stoppingIndex) {
    std::string answer = "\nWinnie the Pooh is not in the " + std::to_string(startingIndex) + '-' + std::to_string(stoppingIndex) + " trees. " +
                         "Bees returned home.\n";
    // Проходим по участку леса и, если там есть Винни Пух, меняем ответ.
    for (int i = startingIndex; i < stoppingIndex; ++i) {
        if (forest[i] == 1) {
            answer = "\nWinnie the Pooh found in the " + std::to_string(startingIndex) + '-' + std::to_string(stoppingIndex) + " trees." +
                     "\nWinnie the Pooh was punished and bees returned home.\n";
            break;
        }
    }
    std::cout << answer;
}

//-------------------------------------------------------
// Раздача задач из портфеля задач каждому потоку.
void Tasks() {
    int startingIndex = 0;
    // Шаг в 10 элементов самый оптимальный.
    int stoppingIndex = 10;
    int count = 0;
    while ((count < tasksNumber) && (startingIndex != -1)) {
        // Создание нового потока и дача ему задачи.
        std::thread newThread(FindingWinnieThePooh, startingIndex, stoppingIndex);
        newThread.join();
        count += 1;
        // Задание индексов для проверки участка леса.
        if ((stoppingIndex + 1) > ((int)forest.size())) {
            startingIndex = -1;
        } else {
            startingIndex = stoppingIndex + 1;
        }
        if ((stoppingIndex + 10) > ((int)forest.size())) {
            stoppingIndex = (int)forest.size() - 1;
        } else {
            stoppingIndex += 10;
        }
    }
}

//-------------------------------------------------------
int main() {
    try {
        srand(time(0));
        // Ввод размера леса.
        int length = EnteringForestLength();
        if (length == -1) {
            return 0;
        }
        // Заполнение леса.
        FillingTheForest(length);
        // Раздача заданий потокам.
        Tasks();
    } catch (std::exception& e) {
        std::cout << e.what();
    }
    return 0;
}
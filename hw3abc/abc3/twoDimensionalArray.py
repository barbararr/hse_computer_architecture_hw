from matrix import Matrix
import random


# ------------------------------------------------------------------------------
# twoDimensionalArray.py - содержит описание обычного двумерного массива.
# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Обычный двумерный массив.
class TwoDimensionalArray(Matrix):
    __size__: int
    __tdaElements__: list

    def __init__(self, size: int):
        super().__init__(size)
        self.__tdaElements__ = []

    # Ввод параметров обычного двумерного массива из файла.
    def read_file(self, line: str):
        self.__tdaElements__ = []
        counter = 0
        nums = list(map(float, line.split()))
        for i in range(0, self.__size__):
            self.__tdaElements__.append([])
            for j in range(0, self.__size__):
                self.__tdaElements__[i].append(nums[counter])
                counter += 1

    # Случайный ввод параметров обычного двумерного массива.
    def random_read(self):
        self.__size__ = random.randint(0, 20) + 1
        self.__tdaElements__ = []
        for i in range(0, self.__size__):
            self.__tdaElements__.append([])
            for j in range(0, self.__size__):
                self.__tdaElements__[i].append(random.random() * random.randint(0, 100))

    # Вывод параметров обычного двумерного массива в файл.
    def write(self) -> str:
        return "It is two dimensional array: dimension = " + str(self.__size__) + ". Arithmetic mean = " + str(
            self.arithmeticMean()) + "\n"

    # Вычисление среднего арифметического обычного двумерного массива.
    def arithmeticMean(self) -> float:
        summ = 0
        for i in range(0, self.__size__):
            for j in range(0, self.__size__):
                summ += self.__tdaElements__[i][j]
        return summ / (self.__size__ * self.__size__)

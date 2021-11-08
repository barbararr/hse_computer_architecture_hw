import random
from matrix import Matrix
from twoDimensionalArray import TwoDimensionalArray
from diagonalMatrix import DiagonalMatrix
from lowerTriangularMatrix import LowerTriangularMatrix


# ------------------------------------------------------------------------------
# container.py - содержит тип данных,
# представляющий простейший контейнер
# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Простейший контейнер на основе одномерного массива.
class Container:
    # Текущая длина.
    __size__: int
    __storage__: list

    # Конструктор контейнера.
    def __init__(self, size: int):
        self.__size__ = size
        self.__storage__ = []

    # Ввод содержимого контейнера из указанного файла.
    def read_file(self, lines: list):
        counter = 0
        for i in range(0, self.__size__):
            matrix_type = int(lines[counter])
            counter += 1
            num = int(lines[counter])
            counter += 1

            if matrix_type == 1:
                m = TwoDimensionalArray(num)
                m.read_file(lines[counter])
                self.__storage__.append(m)
                counter += 1
            elif matrix_type == 2:
                dm = DiagonalMatrix(num)
                dm.read_file(lines[counter])
                self.__storage__.append(dm)
                counter += 1
            else:
                ltm = LowerTriangularMatrix(num)
                ltm.read_file(lines[counter])
                self.__storage__.append(ltm)
                counter += 1

    # Случайный ввод содержимого контейнера.
    def random_read(self):
        for i in range(0, self.__size__):
            matrix_type = random.randint(0, 3)

            if matrix_type == 0:
                m = TwoDimensionalArray(0)
                m.random_read()
                self.__storage__.append(m)
            elif matrix_type == 1:
                dm = DiagonalMatrix(0)
                dm.random_read()
                self.__storage__.append(dm)
            else:
                ltm = LowerTriangularMatrix(0)
                ltm.random_read()
                self.__storage__.append(ltm)

    # Вывод содержимого контейнера в указанный файл.
    def write(self) -> str:
        out_str = "Container contains " + str(self.__size__) + " elements.\n"
        for item in self.__storage__:
            out_str += str(item.write())

        return out_str

    # Сортировка Шелла.
    def shell_sorting(self):
        length = self.__size__
        step = length // 2
        while step > 0:
            for i in range(step, length, 1):
                temp = self.__storage__[i]
                j = i
                while (j >= step) & (self.__storage__[j - step].arithmeticMean() < temp.arithmeticMean()):
                    self.__storage__[j] = self.__storage__[j - step]
                    j -= step
                self.__storage__[j] = temp
            step = step // 2
        pass

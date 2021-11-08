from matrix import Matrix
import random


# ------------------------------------------------------------------------------
# diagonalMatrix.py - содержит описание диагональной матрицы.
# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Диагональная матрица.
class DiagonalMatrix(Matrix):
    __size__: int
    __dmElements__: list

    def __init__(self, size: int):
        super().__init__(size)
        self.__dmElements__ = []

    # Ввод параметров диагональной матрицы из файла.
    def read_file(self, line: str):
        self.__dmElements__ = list(map(float, line.split()))

    # Случайный ввод параметров диагональной матрицы.
    def random_read(self):
        self.__size__ = random.randint(0, 20) + 1
        self.__dmElements__ = []
        for i in range(0, self.__size__):
            self.__dmElements__.append(random.random() * random.randint(0, 100))

    # Вывод параметров диагональной матрицы в файл.
    def write(self) -> str:
        return "It is diagonal matrix: dimension = " + str(self.__size__) + ". Arithmetic mean = " + str(
            self.arithmeticMean()) + "\n"

    # Вычисление среднего арифметического диагональной матрицы.
    def arithmeticMean(self) -> float:
        summ = 0
        for i in range(0, self.__size__):
            summ = summ + self.__dmElements__[i]
        return summ / (self.__size__ * self.__size__)

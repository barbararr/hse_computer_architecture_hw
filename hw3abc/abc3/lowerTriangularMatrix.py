from matrix import Matrix
import random


# ------------------------------------------------------------------------------
# lowerTriangularMatrix.py - содержит описание нижней треугольной матрицы.
# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Нижняя треугольная матрица.
class LowerTriangularMatrix(Matrix):
    __size__: int
    __numberOfElements__: int
    __ltmElements__: list

    def __init__(self, size: int):
        super().__init__(size)
        self.__numberOfElements__ = self.__size__ * (self.__size__ + 1) // 2
        self.__ltmElements__ = []

    # Ввод параметров нижней треугольной матрицы из файла.
    def read_file(self, line: str):
        self.__ltmElements__ = list(map(float, line.split()))

    # Случайный ввод параметров нижней треугольной матрицы.
    def random_read(self):
        self.__size__ = random.randint(0, 20) + 1
        self.__numberOfElements__ = self.__size__ * (self.__size__ + 1) // 2
        self.__ltmElements__ = []
        for i in range(0, self.__numberOfElements__):
            self.__ltmElements__.append(random.random() * random.randint(0, 100))

    # Вывод параметров нижней треугольной матрицы в файл.
    def write(self) -> str:
        return "It is lower triangular matrix: dimension = " + str(self.__size__) + ". Arithmetic mean = " + str(
            self.arithmeticMean()) + "\n"

    # Вычисление среднего арифметического нижней треугольной матрицы.
    def arithmeticMean(self) -> float:
        summ = 0
        for i in range(0, self.__numberOfElements__):
            summ = summ + self.__ltmElements__[i]

        return summ / (self.__size__ * self.__size__)

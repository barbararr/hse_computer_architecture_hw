# ------------------------------------------------------------------------------
# matrix.py - содержит описание обобщающей матрицы.
# ------------------------------------------------------------------------------

# ------------------------------------------------------------------------------
# Структура, обобщающая все имеющиеся матрицы.
class Matrix:
    __size__: int

    def __init__(self, size: int):
        self.__size__ = size

    # Ввод обобщающей матрицы.
    def read_file(self, line: str):
        pass

    # Случайный ввод обобщающей матрицы.
    def random_read(self):
        pass

    # Вывод обобщающей матрицы.
    def write(self) -> str:
        pass

    # Вычисление среднего арифметического обобщенной матрицы.
    def arithmeticMean(self) -> float:
        pass

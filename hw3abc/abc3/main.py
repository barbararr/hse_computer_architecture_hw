from container import Container
import random
import sys
import time

# ------------------------------------------------------------------------------
if __name__ == '__main__':
    print("Start")
    start = time.time()
    random.seed()
    # Контейнер.
    global cont
    argc = len(sys.argv)

    if argc >= 4:
        # Ввод элементов из файла.
        if sys.argv[1] == '-f':
            file_input = open(sys.argv[2], 'r')
            file_output = open(sys.argv[3], 'w')
            input_lines = file_input.readlines()
            cont = Container(int(input_lines[0]))
            input_lines = input_lines[1:]
            cont.read_file(input_lines)

            # Вывод элементов контейнера.
            file_output.write(cont.write())

            # Сортировка контейнера.
            cont.shell_sorting()

            # Вывод отсортированных элементов контейнера.
            file_output.write("\n\nSorted container:\n")
            file_output.write(cont.write())
            file_input.close()
            file_output.close()

        # Генерация рандомных элементов.
        elif sys.argv[1] == '-n':
            # Проверка количества элементов и вывод сообщения об ошибке.
            if (int(sys.argv[2]) > 10000) | (int(sys.argv[2]) < 1):
                print("incorrect number of matrixes. Set 0 < number <= 10000\n")
                exit(3)

            file_output = open(sys.argv[3], 'w')
            cont = Container(int(sys.argv[2]))
            cont.random_read()

            # Вывод элементов контейнера.
            file_output.write(cont.write())

            # Сортировка контейнера.
            cont.shell_sorting()

            # Вывод отсортированных элементов контейнера.
            file_output.write("\n\nSorted container:\n")
            file_output.write(cont.write())
            file_output.close()
    else:
        # Вывод сообщения об ошибке.
        print("Incorrect command line!\nWaited:\n"
              "  Waited:\n"
              "     command -f infile outfile\n"
              "   or   command -n number outfile\n")
        exit(3)
    # Остановка времени.
    end = time.time()
    # Вывод времени.
    print("Total time: " + str((end - start)) + " seconds")
    print("End")

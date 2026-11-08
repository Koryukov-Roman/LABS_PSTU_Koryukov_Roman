#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>

using namespace std;

//? проверяет есть ли отрицательные элементы
bool hasNegativeInRow(int** matrix, int rowIndex, int cols) {
    for (int j = 0; j < cols; j++) {
        if(matrix[rowIndex][j] < 0) { //? проверка каждого элемента строки
            return true; //? если есть "-", возвращает истину
        }
    }
    return false; //? если "-" нет, возвращает ложь
}

//todo вывод двумерного массива на экран
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t"; //! "\t" ровные столбцы
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian.UTF8");
    srand(time(0));

    int rows = 5; //? кол-во строк
    int cols = 4; //? кол-во столбцов

    int** matrix = new int*[rows]; //todo выделяю память для массива
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (rand() % 100) - 30; //? заполнение массива случайными числами от -30 до 69
        }
    }

    cout << "Исходный массив: " << endl;
    printMatrix(matrix, rows, cols);

    //todo проверка
    int checkedRows = 0; //? сколько строк было проверено
    int i = 0; //? индекс текущей строки

    while (checkedRows < rows) {
        if (hasNegativeInRow(matrix, i, cols)) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = 0;
            }

            //todo сдвиг строки в конец
            int* tempRow = matrix[i]; //? адрес обнуленной строки
            for (int k = i; k < rows - 1; k++) {
                matrix[k] = matrix[k + 1]; //? переношу указатели
            }
            matrix[rows - 1] = tempRow; //? убираю обнуленную строку
        } else {
            i++; //? если в строке нет "-"
        }
        checkedRows++; //? засчитывание проверки
    }

    cout << "Итоговый массив: " << endl;
    printMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i]; //? удаление каждой строки из памяти
    }
    delete[] matrix; //? удаление массива указателей

    return 0;
}
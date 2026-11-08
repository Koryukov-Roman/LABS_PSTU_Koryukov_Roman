#include <iostream>
#include <cstdlib>
#include <ctime>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian.UTF8");
    srand(time(0)); //! что бы случайные числа были новыми и не повторялись

    //todo 1. сформировать одномерный массив целых чисел, используя датчик случайных чисел
    int size = 12; //? начальный размер
    int* arr = new int[size]; //? выделение памяти под массив

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; //! случайное число от 0 до 99
    }

    //todo 2. распечатать полученный массив
    cout << "Исходный массив: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    //todo 3. удалить 5 первых элементов массива
    int newSize1 = size - 5;
    int* temp1 = new int[newSize1]; //? создается временный массив меньшего размера

    //? копирование элементов со сдвигом на 5
    for (int i = 0; i < newSize1; i++) {
        temp1[i] = arr[i + 5];
    }

    delete[] arr; //! освобождение памяти от старого массива
    arr = temp1; //todo переносим указатель на новый массив
    size = newSize1;

    //todo 4. Добавить в конец массива 3 новых элемента
    int newSize2 = size + 3;
    int* temp2 = new int[newSize2]; //? создается временный массив большего размера

    //? копирование всех старых элементов
    for (int i = 0; i < newSize2; i++) {
        temp2[i] = arr[i];
    }

    //todo дописываем в конец 3 новых числа
    for (int i = size; i < newSize2; i++) {
        temp2[i] = rand() % 100;
    }

    delete[] arr; //todo освобождение старой памяти
    arr = temp2; //? перенаправление указателя
    size = newSize2;
    cout << "Изменил массив (5 первых удалил, добавил 3 в конец)" << endl << endl;

    //todo 5. распечатать полученный массив
    cout << "Итоговый массив: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; //! очистка памяти

    return 0;
}
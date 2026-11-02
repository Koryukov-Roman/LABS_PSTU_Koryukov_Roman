#include <iostream>
#include <cstdio>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian.UTF8");

    double eps = 0.0001; //? заданная точность 10^-4
    double sum = 0.0; //? Здесь считается сумма
    double a = 0.5; //? Первый член ряда (при n = 1)
    int n = 1; //? Счетчик шагов

    //todo Цикл работает пока элементы >= точности eps
    while (a >= eps) {
        sum = sum + a; //? Добавляем элемент к общей сумме

        n = n + 1; //? Переходим к следующему шагу N
        a = a / (2 * (2 * n - 1));
    }

    printf("Сумма ряда: %.4f\n", sum);

    return 0;
}
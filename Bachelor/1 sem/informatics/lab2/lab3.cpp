#include <iostream>
#include <cstdio>
#include <clocale>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian.UTF8");

    printf("  x   |  Точное Y  |  Сумма (n=20)  |  Сумма (eps) \n");

    double a = 0.1; //? Начало интервала
    double b = 1.0; //? Конец интервала
    int k = 10; //? Число разбиений
    double h = (b - a) / k; //? Шаг изменения x
    double eps = 0.0001; //? Заданная точность
    int n_fixed = 20; //? Число членов

    //todo по х от а до b с шагом h
    for (double x = a; x <= b + h / 2; x += h) {
        //todo значение функции
        double y_exact = exp(cos(x)) * cos(sin(x));

        //todo сумма до n = 20
        double sum_n = 1.0;
        double fact = 1.0;
        for (int i = 1; i <= n_fixed; i++) {
            fact *= i; //? Факториал i
            sum_n += cos(i * x) / fact;
        }

        //todo Сумма eps
        double sum_eps = 1.0;
        fact = 1.0;
        int i = 1;
        double term = cos(i * x) / fact; //? Первый член ряда под знаком суммы

        //todo цикл работает пока модуль >= eps
        while (fabs(term) >= eps) {
            sum_eps += term;
            i++;
            fact *= i;
            term = cos(i * x) / fact;
        }

        printf("%.2f | %.6f | %.6f | %.6f\n", 
               x, y_exact, sum_n, sum_eps);
    }

    return 0;
}
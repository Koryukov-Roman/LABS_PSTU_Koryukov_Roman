#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

//todo функция для сокращения дробей
int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//todo a) функция для вычитания десятичных дробей
double substract(double a, double b) {
    return a - b;
}

//todo б) функция для вычитания обыкновенных дробей
void substract(int num1, int den1, int num2, int den2) {
    if (den1 == 0 || den2 == 0) {
        cout << "Знаменатель не может быть равен нулю." << endl;
        return;
    }

    //todo привожу к общему знаменателю и вычитаю
    int res_num = num1 * den2 - num2 * den1;
    int res_den = den1 * den2;

    //? если числитель равен 0
    if (res_num == 0) {
        cout << "Результат вычитания обыкновенных дробей: 0" << endl;
        return;
    }

    //todo сокращаю дробь
    int divisor = gcd(res_num, res_den);
    res_num /= divisor;
    res_den /= divisor;

    //? если знаменатель отрицательный, то переносим минус в числитель
    if (res_den < 0) {
        res_num = -res_num;
        res_den = -res_den;
    }

    cout << "Результат вычитания дробей: ";
    if (res_den == 1) {
        cout << res_num << endl;
    } else {
        cout << res_num << "/" << res_den << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian.UTF8");

    double d1 = 15.75, d2 = 4.25; //? тестирую вычитание десятичных дробей
    cout << "Вычитание десятичных дробей: " << endl;
    cout << d1 << " - " << d2 << " = " << substract(d1, d2) << endl << endl;

    int n1 = 3, d_1 = 4; //? тестирую вычитание обыкновенных дробей
    int n2 = 1, d_2 = 6; 
    cout << "Вычитание обыкновенных дробей: " << endl;
    cout << n1 << "/" << d_1 << " - " << n2 << "/" << d_2 << endl;
    substract(n1, d_1, n2, d_2);
    
    return 0;
}
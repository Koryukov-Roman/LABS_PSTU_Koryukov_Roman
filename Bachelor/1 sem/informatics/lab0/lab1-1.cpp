#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>

using namespace std;
// Задача №1
int main() {
    setlocale(LC_ALL, "Russian.UTF8");
    //todo float
    float a_f = 100.0f;
    float b_f = 0.001f;
    
    float f_part1 = pow(a_f - b_f, 4); //? (a - b)^4
    float f_part2 = pow(a_f, 4); //? a^4
    float f_part3 = 4.0f * pow(a_f, 3) * b_f; //? 4 * a^3 * b
    float f_part4 = 6.0f * pow(a_f, 2) * pow(b_f, 2); //? 6 * a^2 * b^2
    
    float f_bracket = f_part2 - f_part3 + f_part4; //? Выражение в правых скобках
    float f_num = f_part1 - f_bracket; //? Итоговый числитель

    //todo Расчет знаменателя
    float f_part5 = pow(b_f, 4); //? b^4
    float f_part6 = 4.0f * a_f * pow(b_f, 3); //? 4 * a * b^3
    float f_den = f_part5 - f_part6; //? Итоговый знаменатель

    float res_f = f_num / f_den; //? Результат

    //todo double
    double a_d = 100.0;
    double b_d = 0.001;

    double d_part1 = pow(a_d - b_d, 4);
    double d_part2 = pow(a_d, 4);
    double d_part3 = 4.0 * pow(a_d, 3) * b_d;
    double d_part4 = 6.0 * pow(a_d, 2) * pow(b_d, 2);

    double d_bracket = d_part2 - d_part3 + d_part4;
    double d_num = d_part1 - d_bracket;

    //todo Расчет знаменателя
    double d_part5 = pow(b_d, 4);
    double d_part6 = 4.0 * a_d * pow(b_d, 3);
    double d_den = d_part5 - d_part6;

    double res_d = d_num / d_den;

    cout << "Для float" << endl;
    cout << "(a - b)^4 = " << f_part1 << endl;
    cout << "a^4 - 4a^3b + 6a^2b^2 = " << f_bracket << endl;
    cout << "Числитель (num) = " << f_num << endl;
    cout << "Знаменатель (den) = " << f_den << endl;
    cout << "Результат float = " << res_f << endl << endl;

    cout << "Для double" << endl;
    cout << "(a - b)^4 = " << d_part1 << endl;
    cout << "a^4 - 4a^3b + 6a^2b^2 = " << d_bracket << endl;
    cout << "Числитель (num) = " << d_num << endl;
    cout << "Знаменатель (den) = " << d_den << endl;
    cout << "Результат double = " << res_d;

    return 0;
}
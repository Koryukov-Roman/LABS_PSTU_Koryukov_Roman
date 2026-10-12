#include <iostream>

using namespace std;

// Задача №2
int main() {
    int n, m;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    int start_n = n;
    int start_m = m;

    int res1 = n-- - m;
    cout << "1) " << res1 << endl;

    n = start_n; m = start_m;

    bool res2 = m-- < n;
    cout << "2) " << boolalpha << res2 << endl;

    n = start_n; m = start_m;

    bool res3 = n++ > m;
    cout << "3) " << boolalpha << res3 << endl;

    return 0;
}
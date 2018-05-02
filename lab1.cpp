#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double z1(double b) {
    double numerator = sqrt(2 * b + 2 * sqrt(b * b - 4));
    double denominator = sqrt(b * b - 4) + b + 2;
    return numerator / denominator;
}

double z2(double b) {
    return 1 / sqrt(b + 2);
}

double readNumber() {
    double b;
    while (true) {
        cout << "Введите число: ";
        cin >> b;
        if (cin.good()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        } else {
            cin.clear();
            cerr << "Некорректный ввод!";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return b;
}

int main()
{
    setlocale(0, "Rus");
    double b = readNumber();
    cout << "b = " << b << endl;
    cout << "z1 = " << z1(b) << endl;
    cout << "z2 = " << z2(b) << endl;
    cin.get();
    return 0;
}

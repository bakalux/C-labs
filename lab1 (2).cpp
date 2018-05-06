#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double z1(double a) {
    double numerator = cos(a) + sin(a);
    double denominator = cos(a) - sin(a);
    return numerator / denominator;
}

double z2(double a) {
    return tan(2 * a) + 1. / cos(2 * a);
}

double readNumber() {
    double aDegrees;
    while (true) {
        cout << "Введите a (в градусах): ";
        cin >> aDegrees;
        if (cin.good()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        } else {
            cin.clear();
            cerr << "Некорректный ввод!";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return aDegrees;
}

int main()
{
    setlocale(0, "Rus");
    double PI = 4.0 * atan(1.); 
    double aDegrees = readNumber();
    double a = aDegrees / PI * 180;
    cout << "a = " << a << endl;
    cout << "z1 = " << z1(a) << endl;
    cout << "z2 = " << z2(a) << endl;
    cin.get();
    return 0;
}
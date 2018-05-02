#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double readNumber(string numberName) {
    double number;
    while (true) {
        cout << "Введите число " << numberName << ": ";
        cin >> number;
        if (cin.good()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        } else {
            cin.clear();
            cerr << "Некорректный ввод!" << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return number;
}

bool isInArea(double x, double y) {
    return (x >= 0) && (x <= 1) && (y >= 0) && (y <= 1) && (sqrt(x * x + y * y) >= 1);
}

int main()
{
    setlocale(0, "Rus");
    double x = readNumber("x");
    double y = readNumber("y");
    cout << (isInArea(x, y) ? "Точка в области" : "Точка вне области") << endl;
    cin.get();
    return 0;
}

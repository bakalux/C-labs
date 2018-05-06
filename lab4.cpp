#include <iostream>
#include <limits>
#include <iomanip>  

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

double f(double x, double a, double b, double c) {
    if (x + c < 0 && a != 0) {
        return -a * x * x * x - b;
    }
    
    if (x + c > 0 && a == 0) {
        return (x - a) / (x - c);
    }
    
    return x / c + c / x;
}

int main()
{
    setlocale(0, "Rus");
    double a = readNumber("a");
    double b = readNumber("b");
    double c = readNumber("c");
    double xStart = readNumber("xStart");
    double xEnd = readNumber("xEnd");
    double dx = readNumber("dx");
    
    // -10 .. 5
    cout << setw(4) << "x" << " " << "f(x)" << endl;
    for (double x = xStart; x <= xEnd; x = x + dx) {
        cout << setw(4) << x << " " << f(x, a, b, c) << endl;
    }
    
    cin.get();
    return 0;
}
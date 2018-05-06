#include <iostream>
#include <limits>

using namespace std;

unsigned int inputNumber() {
    unsigned int number;
    cout << "Введите x (>= 0): ";
    cin >> hex >> number;
    while (!cin.good() || number < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Некорректный ввод. Пожалуйста, повторите:" << endl;
        cout << "Введите x (>= 0): ";
        cin >> hex >> number;
    }
    return number;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    unsigned int x = inputNumber();
    unsigned int h = x & 0xF;
    unsigned int m = (x >> 5) & 0x3F;
    unsigned int s = (x >> 11) & 0xF;
    
    cout << dec << "Десятичное значение S: " << s << endl;
    cout << dec << "Десятичное значение M: " << m << endl;
    cout << dec << "Десятичное значение H: " << h << endl;
    
    return 0;
}

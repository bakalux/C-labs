#include <iostream>
#include <limits>

using namespace std;

unsigned int inputNumber(char* varName, unsigned int maxValue) {
    unsigned int number;
    cout << "Введите " << varName << " (0 <= " << varName << " <= " << maxValue << "): ";
    cin >> number;
    while (!cin.good() || number > maxValue) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Некорректный ввод. Пожалуйста, повторите:" << endl;
        cout << "Введите " << varName << " (0 <= " << varName << " <= " << maxValue << "): ";
        cin >> number;
    }
    return number;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    
    unsigned int s = inputNumber("S", 31);
    unsigned int m = inputNumber("M", 63);
    unsigned int h = inputNumber("H", 31);
    
    cout << "Вывод числа в шестнадцатеричном виде: ";
    unsigned int x = h | m << 5 | s << 11;
    cout << hex << x << endl;
    
    return 0;
}

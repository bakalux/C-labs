#include <iostream> 
#include <cmath>
#include <limits>

using namespace std;

string arrayToString(double arr[], int length) {
    string s = "[";
    int i = 0;
    while (true) {
        if (i + 1 < length) {
            s += to_string(arr[i]) + ", ";
            i++;
        } else {
            s += to_string(arr[i]);
            break;
        }
    }
    s += "]";
    return s;
}

double calculateArraySum(double arr[], int length) {
    double sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    return sum;
}

double calculateArraySumAfterMin(double arr[], int length) {
    int iMin = 0;
    if (length > 1) {
        for (int i = 1; i < length; i++) {
            if (arr[i] < arr[iMin]) {
                iMin = i;
            }
        }
    }
    
    double sum = 0;
    for (int i = iMin + 1; i < length; i++) {
        sum += arr[i];
    }
    
    return sum;
}

void sort(double arr[], int length) {
    for (int i = 0; i < length - 1; i++) { 
        for (int j = 0; j < length - i - 1; j++) { 
            if (abs(arr[j]) > abs(arr[j + 1])) {
                double tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    setlocale(0, "Rus");
    const int n = 10;
    double arr[] = {1.111, 2, 0, -1, 12.3, -27.43, 13, 7, 0, -1.1};
    
    cout << "Исходный массив: " << arrayToString(arr, n) << endl;
    cout << "Сумма элементов массива: " << calculateArraySum(arr, n) << endl;
    cout << "Сумма элементов массива после минимального: " << calculateArraySumAfterMin(arr, n) << endl;
    sort(arr, n);
    cout << "Упорядоченный по возрастанию модулей массив: " << arrayToString(arr, n) << endl;

    return 0;
}
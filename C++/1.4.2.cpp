#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, countXi = 0;

    // Вводим количество элементов массивов
    cout << "Enter the number of elements: ";
    cin >> n;

    // Проверка на корректность количества элементов
    if (n <= 0) {
        cout << "The number of elements must be greater than 0" << endl;
        return 1;
    }

    // Инициализируем массивы
    vector<double> X(n), Y(n), T(n);

    // Вводим данные для массивов X и Y
    for (int i = 0; i < n; i++) {
        cout << "Enter element X" << i + 1 << ": ";
        cin >> X[i];
        cout << "Enter element Y" << i + 1 << ": ";
        cin >> Y[i];
    }

    // Цикл для вычисления массива T и подсчета элементов, которые получили значения из массива X
    for (int i = 0; i < n; i++) {
        if (X[i] > Y[i]) {
            T[i] = X[i];
            countXi++;
        } else {
            T[i] = Y[i];
        }
    }

    // Выводим массив T
    cout << "Array T:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "T" << i + 1 << ": " << fixed << setprecision(4) << T[i] << endl;
    }

    // Выводим количество элементов, которые получили значения из массива X
    cout << "Amount of elements, which received values from array X: " << countXi << endl;

    return 0;
}
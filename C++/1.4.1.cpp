#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    double totalVolume = 0.0;

    // Вводим количество резервуаров
    cout << "Enter the number of tanks: ";
    cin >> n;

    if (n < 1) {
        cout << "The number of tanks must be greater than 0" << endl;
        return 1;
    }

    // Инициализируем массивы
    vector<double> R(n), H(n);

    // Вводим данные для каждого резервуара
    for (int i = 0; i < n; i++) {
        cout << "Enter radius R" << i + 1 << ": ";
        cin >> R[i];
        if (R[i] < 0) {
            cout << "Radius cannot be negative" << endl;
            return 1;
        }

        cout << "Enter filling level H" << i + 1 << ": ";
        cin >> H[i];
        if (H[i] < 0) {
            cout << "The filling level cannot be negative" << endl;
            return 1;
        }

        if (H[i] > R[i]) {
            cout << "The filling level cannot exceed the radius of the tank" << endl;
            return 1;
        }
    }

    // Цикл для вычисления объема горючего в каждом резервуаре
    for (int i = 0; i < n; i++) {
        // Вычисляем объем горючего в текущем резервуаре
        double volume = M_PI * pow(H[i], 2) * (R[i] - H[i] / 3.0);

        // Суммируем объемы
        totalVolume += volume;
    }

    // Выводим общий объем горючего
    cout << fixed << setprecision(4) << "Total fuel volume: " << totalVolume << endl;

    return 0;
}
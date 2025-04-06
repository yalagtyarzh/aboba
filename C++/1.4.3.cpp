#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

int main() {
    int n;

    // Вводим количество элементов массивов
    cout << "Enter the number of elements: ";
    cin >> n;

    // Проверка на корректность количества элементов
    if (n <= 0) {
        cout << "The number of elements must be greater than 0" << endl;
        return 1;
    }

    // Инициализируем массивы
    vector<double> A(n), C(n);

    // Вводим данные для массивов A и C
    for (int i = 0; i < n; i++) {
        cout << "Enter element A" << i + 1 << ": ";
        cin >> A[i];
        cout << "Enter element C" << i + 1 << ": ";
        cin >> C[i];
    }

    // Инициализируем минимальное произведение большим значением
    double minProduct = numeric_limits<double>::max();

    // Цикл для вычисления произведений и нахождения наименьшего среди них
    for (int i = 1; i <= n; i++) {
        double product = 1;
        for (int j = 0; j < i; j++) {
            product *= (A[j] + C[j]);
        }
        if (product < minProduct) {
            minProduct = product;
        }
    }

    // Выводим наименьшее произведение
    cout << fixed << setprecision(4) << "The lowest value: " << minProduct << endl;

    return 0;
}
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x = 0.5, result, productTerm, lnTerm;
    int n = 20, k;

    // Кубический корень из x^2 через pow
    result = n * pow(x, 2.0 / 3.0);

    // Переменная для произведения
    productTerm = 1.0;

    // Вычисление произведения
    for (k = 1; k <= n; k++) {
        // Проверка на корректность аргумента для sqrt и ln
        if (k * fabs(x) < 0) {
            cout << "The argument to Sqrt must be non-negative" << endl;
            continue;
        }

        lnTerm = log(sqrt(k * fabs(x)) + 1);

        // Проверка на корректность аргумента для ln
        if (lnTerm <= 0) {
            cout << "The argument for Ln must be positive" << endl;
            continue;
        }

        // Проверка деления на ноль
        if ((1.02 - 1.0 / k) == 0) {
            cout << "Division by zero" << endl;
            continue;
        }

        productTerm *= (lnTerm / (1.02 - 1.0 / k));
        cout << "Product in iteration: " << k << " - " << productTerm << endl;
    }

    // Итоговая формула
    result += productTerm;

    cout << "Result: " << result << endl;

    return 0;
}
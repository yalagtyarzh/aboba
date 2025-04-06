#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double A = 1.5;       // Значение A
    double X1 = 0.0;      // Начальное значение X
    double dX = A / 5.0;  // Шаг изменения X
    int N = 10;           // Количество значений
    double X = X1, Y;

    cout << "  X    |  Y  " << endl;
    cout << "-------------" << endl;

    // Вычисляем N значений функции Y
    for (int i = 1; i <= N; i++) {
        // Общая часть формулы для обеих ветвей
        if ((4 * pow(A, 2) < 0) || (pow((X + 2 * A), 2) < 0)) {
            cout << "Negative value under the root" << endl;
            X += dX;
            continue;
        }

        Y = pow(4 * pow(A, 2), 1.0 / 3.0) - pow(pow((X + 2 * A), 2), 1.0 / 3.0);

        if (Y < 0) {
            cout << fixed << setprecision(2) << X << "\t" << "not exist" << endl;
            X += dX;
            continue;
        }

        if (X < 0) {
            // При x < 0: выражение под корнем
            if (Y < 0) {
                cout << "Negative value under the root" << endl;
                X += dX;
                continue;
            }
            Y = pow(Y, 3.0 / 2.0);
        } else {
            // При x >= 0: минус выносится за корень
            Y = -pow(abs(Y), 3.0 / 2.0);
        }

        // Выводим значение X и соответствующее значение Y
        cout << fixed << setprecision(2) << X << "\t" << setprecision(4) << Y << endl;

        // Увеличиваем X на шаг dX
        X += dX;
    }

    return 0;
}
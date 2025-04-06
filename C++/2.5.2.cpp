#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    const int MAX_SIZE = 100;
    int n;
    double sumDiagonal = 0.0;

    // Вводим размер матрицы
    cout << "Enter the size of the matrix n: ";
    cin >> n;

    // Проверка на корректность размера матрицы
    if (n <= 0 || n > MAX_SIZE) {
        cout << "The size of the matrix must be between 1 and " << MAX_SIZE << endl;
        return 1;
    }

    // Инициализируем матрицу
    vector<vector<double>> A(n, vector<double>(n));

    // Вводим данные для матрицы
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter element A[" << i + 1 << "," << j + 1 << "]: ";
            cin >> A[i][j];
        }
    }

    // Выводим матрицу после ввода данных
    cout << "\nMatrix after input:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << fixed << setprecision(2) << A[i][j] << " ";
        }
        cout << endl;
    }

    // Двукратный цикл для изменения элементов под главной диагональю и вычисления суммы главной диагонали
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                sumDiagonal += A[i][j];
            } else if (i > j) {
                if (A[i][j] > A[j][i]) {
                    A[i][j] = (A[i][j] + A[j][i]) / 2.0;
                }
            }
        }
    }

    // Выводим измененную матрицу
    cout << "\nModified matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << fixed << setprecision(2) << A[i][j] << " ";
        }
        cout << endl;
    }

    // Выводим сумму элементов главной диагонали
    cout << "Sum of the elements of the main diagonal: " << fixed << setprecision(2) << sumDiagonal << endl;

    return 0;
}
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 5;

void InputMatrix(vector<vector<double>>& M) {
    cout << "Enter the elements of the matrix A:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "Enter element A[" << i + 1 << "," << j + 1 << "]: ";
            cin >> M[i][j];
        }
    }
}

void InputVector(vector<double>& V) {
    cout << "Enter the elements of the array C:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter element C[" << i + 1 << "]: ";
        cin >> V[i];
    }
}

int main() {
    vector<vector<double>> A(SIZE, vector<double>(SIZE));
    vector<double> C(SIZE);
    bool hasEqualElements = false;

    // Вводим данные для матрицы A
    InputMatrix(A);

    // Выводим матрицу после ввода данных
    cout << "\nMatrix A after input:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << fixed << setprecision(2) << A[i][j] << " ";
        }
        cout << endl;
    }

    // Вводим данные для массива C
    InputVector(C);

    // Проверяем, имеются ли равные элементы в массиве C
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (C[i] == C[j]) {
                hasEqualElements = true;
                break;
            }
        }
        if (hasEqualElements) break;
    }

    // Если имеются равные элементы, изменяем значения элементов массива C
    if (hasEqualElements) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                C[i] += A[j][i];
            }
        }
    }

    // Выводим измененный массив C
    cout << "\nModified array C:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "C[" << i + 1 << "]: " << fixed << setprecision(2) << C[i] << endl;
    }

    return 0;
}
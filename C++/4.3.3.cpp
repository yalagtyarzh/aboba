#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

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

void FindMaxRowSum(const vector<vector<double>>& M, int& maxIndex, double& maxSum) {
    maxSum = numeric_limits<double>::lowest();
    for (int i = 0; i < SIZE; i++) {
        double sum = 0;
        for (int j = 0; j < SIZE; j++) {
            sum += M[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxIndex = i;
        }
    }
}

void FindMaxColSum(const vector<vector<double>>& M, int& maxIndex, double& maxSum) {
    maxSum = numeric_limits<double>::lowest();
    for (int j = 0; j < SIZE; j++) {
        double sum = 0;
        for (int i = 0; i < SIZE; i++) {
            sum += M[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxIndex = j;
        }
    }
}

void CalculateSum(const vector<vector<double>>& M, int rowIndex, int colIndex, double& sum) {
    sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += M[rowIndex][i] + M[i][colIndex];
    }
    // Убираем двойной счет элемента на пересечении строки и столбца
    sum -= M[rowIndex][colIndex];
}

int main() {
    vector<vector<double>> A(SIZE, vector<double>(SIZE));
    int maxRowIndex = 0, maxColIndex = 0;
    double maxRowSum = 0, maxColSum = 0;

    // Вводим данные для матрицы
    InputMatrix(A);

    // Выводим матрицу после ввода данных
    cout << "\nMatrix A after input:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << fixed << setprecision(2) << A[i][j] << " ";
        }
        cout << endl;
    }

    // Находим строку с максимальной суммой элементов
    FindMaxRowSum(A, maxRowIndex, maxRowSum);

    // Находим столбец с максимальной суммой элементов
    FindMaxColSum(A, maxColIndex, maxColSum);

    // Проверяем, совпадают ли номера строки и столбца
    if (maxRowIndex == maxColIndex) {
        // Вычисляем сумму элементов строки и столбца
        CalculateSum(A, maxRowIndex, maxColIndex, maxRowSum);
        cout << "Sum of the elements of the row and column: " << fixed << setprecision(2) << maxRowSum << endl;
    } else {
        // Выводим номера строки и столбца с максимальными суммами
        cout << "Row with the maximum sum: " << maxRowIndex + 1 << endl;
        cout << "Column with the maximum sum: " << maxColIndex + 1 << endl;
    }

    return 0;
}
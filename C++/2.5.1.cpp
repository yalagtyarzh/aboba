#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    const int ROWS = 10;
    const int COLS = 2;
    vector<vector<int>> students(ROWS, vector<int>(COLS));
    int count = 0;
    double percentage;

    // Вводим данные для матрицы
    for (int i = 0; i < ROWS; i++) {
        cout << "Enter the total number of students in the group " << i + 1 << ": ";
        cin >> students[i][0];
        if (students[i][0] < 0) {
            cout << "The total number of students cannot be negative" << endl;
            return 1;
        }

        cout << "Enter the number of excellent students in the group " << i + 1 << ": ";
        cin >> students[i][1];
        if (students[i][1] < 0) {
            cout << "The number of excellent students cannot be negative" << endl;
            return 1;
        }

        if (students[i][1] > students[i][0]) {
            cout << "The number of excellent students cannot exceed the total number of students" << endl;
            return 1;
        }
    }

    // Выводим матрицу после ввода данных
    cout << "\nMatrix of students (Total | Excellent):" << endl;
    for (int i = 0; i < ROWS; i++) {
        cout << "Group " << i + 1 << ": " << students[i][0] << " | " << students[i][1] << endl;
    }

    // Выводим заголовок таблицы
    cout << "\nGroups with more than 15% excellent students:" << endl;
    cout << "-------------------------------" << endl;

    // Цикл для проверки условия и вывода номеров групп
    for (int i = 0; i < ROWS; i++) {
        if (students[i][0] == 0) {
            cout << "The total number of students in group " << i + 1 << " is zero, cannot calculate percentage" << endl;
            continue;
        }

        percentage = (static_cast<double>(students[i][1]) / students[i][0]) * 100;
        if (percentage > 15) {
            cout << "Group " << i + 1 << endl;
            count++;
        }
    }

    // Выводим общее число таких групп
    cout << "Total number of groups with more than 15% excellent students: " << count << endl;

    return 0;
}
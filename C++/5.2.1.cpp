#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Student {
    string Group;
    string FIO;
    int BirthYear;
    char Gender;
    vector<int> PhysicsGrades;
    vector<int> MathGrades;
    vector<int> InformaticsGrades;
    double Scholarship;
};

// Функция для вычисления среднего значения оценок
double CalculateAverage(const vector<int>& Grades) {
    int sum = 0;
    for (int grade : Grades) {
        sum += grade;
    }
    return static_cast<double>(sum) / Grades.size();
}

int main() {
    int n;
    string group;
    vector<Student> Students;

    // Вводим количество студентов
    cout << "Enter the number of students: ";
    cin >> n;

    if (n < 1) {
        cout << "The number of students must be greater than 0" << endl;
        return 1;
    }

    // Вводим данные о студентах
    for (int i = 0; i < n; i++) {
        Student student;
        cout << "Enter data for student " << i + 1 << ":" << endl;

        cout << "Group: ";
        cin >> student.Group;
        if (student.Group.empty()) {
            cout << "Group cannot be empty" << endl;
            return 1;
        }

        cout << "FIO: ";
        cin.ignore();
        getline(cin, student.FIO);

        cout << "Birth Year: ";
        cin >> student.BirthYear;

        cout << "Gender (M/F): ";
        cin >> student.Gender;
        if (student.Gender != 'M' && student.Gender != 'F') {
            cout << "Gender must be M or F" << endl;
            return 1;
        }

        cout << "Physics grades (5 values): ";
        student.PhysicsGrades.resize(5);
        for (int& grade : student.PhysicsGrades) {
            cin >> grade;
            if (grade < 0 || grade > 5) {
                cout << "Grades must be between 0 and 5" << endl;
                return 1;
            }
        }

        cout << "Math grades (5 values): ";
        student.MathGrades.resize(5);
        for (int& grade : student.MathGrades) {
            cin >> grade;
            if (grade < 0 || grade > 5) {
                cout << "Grades must be between 0 and 5" << endl;
                return 1;
            }
        }

        cout << "Computer Science grades (5 values): ";
        student.InformaticsGrades.resize(5);
        for (int& grade : student.InformaticsGrades) {
            cin >> grade;
            if (grade < 0 || grade > 5) {
                cout << "Grades must be between 0 and 5" << endl;
                return 1;
            }
        }

        cout << "Scholarship: ";
        cin >> student.Scholarship;
        if (student.Scholarship < 0) {
            cout << "Scholarship cannot be negative" << endl;
            return 1;
        }

        Students.push_back(student);
    }

    // Вводим номер группы для поиска
    cout << "Enter group number to search: ";
    cin >> group;

    // Выводим студентов заданной группы с средним баллом больше 4.5
    cout << "Students of the group " << group << " with an average score greater than 4.5:" << endl;
    int count = 0;
    for (const auto& student : Students) {
        if (student.Group == group) {
            double avgPhysics = CalculateAverage(student.PhysicsGrades);
            double avgMath = CalculateAverage(student.MathGrades);
            double avgInformatics = CalculateAverage(student.InformaticsGrades);
            double avgTotal = (avgPhysics + avgMath + avgInformatics) / 3.0;

            if (avgTotal > 4.5) {
                cout << student.FIO << " - Average score: " << fixed << setprecision(2) << avgTotal << endl;
                count++;
            }
        }
    }

    if (count == 0) {
        cout << "No students with an average score greater than 4.5 in the group " << group << endl;
    }

    return 0;
}
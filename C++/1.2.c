#include <stdio.h>
#include <math.h>

int main() {
    int N = 10, i;
    double A = 0.55, B = 1.0, x, step, result;

    // Вычисляем шаг
    step = (B - A) / (N - 1);

    // Выводим заголовок таблицы
    printf("  X    |  f(X)\n");
    printf("---------------\n");

    // Цикл для вычисления и вывода значений функции
    for (i = 0; i < N; i++) {
        x = A + i * step;

        // Проверка на деление на ноль и корректность аргумента для Sqrt
        if (x <= 0) {
            printf("x must be greater than 0\n");
            continue;
        }

        // Проверка на корректность аргумента для Ln
        if (fabs(0.2 + sin(x)) <= 0) {
            printf("Argument to Ln must be included.\n");
            continue;
        }

        result = (1 / sqrt(x)) + pow(log(fabs(0.2 + sin(x))), 2) * pow(x, 2.0 / 3.0);
        printf("%0.4f | %0.4f\n", x, result);
    }

    return 0;
}
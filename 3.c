#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "RUS");

    printf("Построение фигуры: Заполненный ромбоид (дельтоид)\n");

    int a;
    printf("Введите высоту верхней части a (> 0): ");
    if (scanf("%d", &a) != 1 || a <= 0)
    {
        printf("Ошибка: высота a должна быть натуральным числом (> 0).\n");
        return 1;
    }

    int b;
    printf("Введите высоту нижней части b (> 0): ");
    if (scanf("%d", &b) != 1 || b <= 0)
    {
        printf("Ошибка: высота b должна быть натуральным числом (> 0).\n");
        return 1;
    }

    char c;
    printf("Введите символ для рисования: ");
    if (scanf(" %c", &c) != 1)
    {
        printf("Ошибка: некорректный ввод символа.\n");
        return 1;
    }

    printf("\nРезультат построения (%d x %d):\n\n", a, b);

    for (int i = 0; i < a; i++)
    {
        int spaces = a - 1 - i;
        int count = 2 * i + 1;

        for (int s = 0; s < spaces; s++)
        {
            putchar(' ');
        }
        for (int k = 0; k < count; k++)
        {
            putchar(c);
        }
        putchar('\n');
    }

    if (b > 1)
    {
        for (int step = 1; step < b; step++)
        {
            int w = (int)(((double)(a - 1) * (b - 1 - step)) / (b - 1) + 0.5);
            int spaces = (a - 1) - w;
            int count = 2 * w + 1;

            for (int s = 0; s < spaces; s++)
            {
                putchar(' ');
            }
            for (int k = 0; k < count; k++)
            {
                putchar(c);
            }
            putchar('\n');
        }
    }

    return 0;
}

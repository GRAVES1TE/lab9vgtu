#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "RUS");

    printf("Выберите режим отображения таблицы умножения:\n");
    printf("1 — Полная таблица Пифагора (10x10)\n");
    printf("2 — Левый нижний треугольник таблицы (j <= i)\n");
    printf("3 — Вывести оба варианта\n");
    printf("Ваш выбор (1-3): ");

    int choice;
    if (scanf("%d", &choice) != 1)
    {
        printf("Ошибка: некорректный ввод.\n");
        return 1;
    }

    if (choice < 1 || choice > 3)
    {
        printf("Ошибка: выбран недопустимый режим (введите число от 1 до 3).\n");
        return 1;
    }

    if (choice == 1 || choice == 3)
    {
        printf("\n=== Полная таблица Пифагора (10x10) ===\n\n");
        printf("    |");
        for (int j = 1; j <= 10; j++)
        {
            printf("%4d", j);
        }
        printf("\n----+-----------------------------------------\n");

        for (int i = 1; i <= 10; i++)
        {
            printf("%3d |", i);
            for (int j = 1; j <= 10; j++)
            {
                printf("%4d", i * j);
            }
            printf("\n");
        }
    }

    if (choice == 2 || choice == 3)
    {
        printf("\n=== Левый нижний треугольник таблицы Пифагора (j <= i) ===\n\n");
        printf("    |");
        for (int j = 1; j <= 10; j++)
        {
            printf("%4d", j);
        }
        printf("\n----+-----------------------------------------\n");

        for (int i = 1; i <= 10; i++)
        {
            printf("%3d |", i);
            for (int j = 1; j <= i; j++)
            {
                printf("%4d", i * j);
            }
            printf("\n");
        }
    }

    return 0;
}

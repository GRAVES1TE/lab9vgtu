#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_ALL, "RUS");

    char answer;

    do
    {
        printf("Введите целое число: ");
        long long num;

        if (scanf("%lld", &num) != 1)
        {
            printf("Ошибка: некорректный ввод числа.\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF);

            printf("\nПродолжить работу программы? (y/n): ");
            if (scanf(" %c", &answer) != 1)
            {
                break;
            }

            while ((ch = getchar()) != '\n' && ch != EOF);
            printf("\n");
            continue;
        }

        unsigned long long u_num;
        if (num < 0)
        {
            u_num = 0ULL - (unsigned long long)num;
        }
        else
        {
            u_num = (unsigned long long)num;
        }

        int digits[32];
        int count = 0;

        if (u_num == 0)
        {
            digits[0] = 0;
            count = 1;
        }
        else
        {
            int rev_digits[32];
            int rev_count = 0;
            unsigned long long temp = u_num;

            while (temp > 0)
            {
                rev_digits[rev_count++] = (int)(temp % 10);
                temp /= 10;
            }

            for (int i = 0; i < rev_count; i++)
            {
                digits[i] = rev_digits[rev_count - 1 - i];
            }
            count = rev_count;
        }

        printf("\nИсходное число: %lld\n", num);
        printf("Количество цифр: %d\n", count);
        printf("Цифры числа (слева направо): ");
        for (int i = 0; i < count; i++)
        {
            printf("%d ", digits[i]);
        }
        printf("\n");

        int last_digit = digits[count - 1];
        printf("Последняя цифра числа: %d\n", last_digit);

        if (count == 1)
        {
            printf("Число состоит из одной цифры. Цифры, кроме последней, отсутствуют.\n");
            printf("Сумма четных цифр, исключая последнюю: 0\n");
        }
        else
        {
            printf("Цифры, исключая последнюю: ");
            for (int i = 0; i < count - 1; i++)
            {
                printf("%d ", digits[i]);
            }
            printf("\n");

            long long even_sum = 0;
            int even_count = 0;

            printf("Четные цифры (из оставшихся): ");
            for (int i = 0; i < count - 1; i++)
            {
                if (digits[i] % 2 == 0)
                {
                    printf("%d ", digits[i]);
                    even_sum += digits[i];
                    even_count++;
                }
            }

            if (even_count == 0)
            {
                printf("отсутствуют");
            }
            printf("\n");

            printf("Сумма четных цифр, исключая последнюю: %lld\n", even_sum);
        }

        printf("\nПродолжить работу программы? (y/n): ");
        if (scanf(" %c", &answer) != 1)
        {
            break;
        }

        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        printf("\n");

    } while (answer == 'y' || answer == 'Y' || answer == 'd' || answer == 'D');

    return 0;
}

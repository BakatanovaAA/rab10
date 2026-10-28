#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

double area_square(double a);
char square_symbol(int row, int col, char sym);

int main(void)
{
    char sym, c;
    int side;
    int choice;
    int row, col;
    double s;

    setlocale(LC_ALL, "");

    printf("Фигура: закрашенный квадрат\n");
    printf("Введите символ, из которого будет строиться фигура: ");
    scanf(" %c", &sym);
    printf("Введите сторону квадрата (в символах): ");
    scanf("%d", &side);

    if (side < 1)
        printf("Ошибка: сторона должна быть больше 0\n");
    else
    {
        do
        {
            printf("\nМеню:\n");
            printf("1 - рассчитать площадь\n");
            printf("2 - вывести определение фигуры\n");
            printf("3 - нарисовать фигуру\n");
            printf("0 - выход\n");
            printf("Ваш выбор: ");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                s = area_square(side);
                printf("Площадь квадрата = %.2f\n", s);
                break;
            case 2:
                printf("Квадрат - это прямоугольник, у которого все стороны равны.\n");
                printf("Все углы квадрата прямые (по 90 градусов).\n");
                break;
            case 3:
                for (row = 1; row <= side; row++)
                {
                    for (col = 1; col <= side; col++)
                    {
                        c = square_symbol(row, col, sym);
                        putchar(c);
                    }
                    printf("\n");
                }
                break;
            case 0:
                printf("Выход из программы\n");
                break;
            default:
                printf("Неизвестный пункт меню\n");
                break;
            }
        } while (choice != 0);
    }

    return 0;
}


/* Площадь квадрата со стороной a */
double area_square(double a)
{
    double s;
    s = a * a;
    return s;
}

char square_symbol(int row, int col, char sym)
{
    char result;
    result = sym;
    return result;
}
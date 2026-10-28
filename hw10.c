#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

double area_rectangle(double a, double b);
char figure_symbol(int row, int col, int height, int width, char sym);

int main(void)
{
    char sym, c;
    int height, width;
    int choice;
    int row, col;
    double s;

    setlocale(LC_ALL, "");

    printf("Фигура: пустой прямоугольник\n");
    printf("Введите символ, из которого будет строиться фигура: ");
    scanf(" %c", &sym);
    printf("Введите высоту (в символах): ");
    scanf("%d", &height);
    printf("Введите ширину (в символах): ");
    scanf("%d", &width);

    if (height < 1 || width < 1)
        printf("Ошибка: высота и ширина должны быть больше 0\n");
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
                s = area_rectangle(height, width);
                printf("Площадь прямоугольника = %.2f\n", s);
                break;
            case 2:
                printf("Прямоугольник - это четырёхугольник, у которого все углы прямые (по 90 градусов).\n");
                printf("Противоположные стороны прямоугольника равны и параллельны.\n");
                break;
            case 3:
                for (row = 1; row <= height; row++)
                {
                    for (col = 1; col <= width; col++)
                    {
                        c = figure_symbol(row, col, height, width, sym);
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

double area_rectangle(double a, double b)
{
    double s;
    s = a * b;
    return s;
}

char figure_symbol(int row, int col, int height, int width, char sym)
{
    char result;

    if (row == 1 || row == height || col == 1 || col == width)
        result = sym;
    else
        result = ' ';

    return result;
}
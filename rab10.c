#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

double fa(double x);
double fb(double x);
double product(double a, double b);
double diff_squares(double a, double b);
double double_sum(double a, double b);
double sin_n(double x, int N);
double sin_eps(double x, double eps);
double exp_neg_n(double x, int N);
double exp_neg_eps(double x, double eps);

int main(void)
{
    double x, f1, f2;
    double res;
    int choice;
    int N, i;
    double eps;
    double s_std, s_n, s_eps;
    double e_std, e_n, e_eps;

    setlocale(LC_ALL, "");

    /* Задание 1. Значения двух функций */
    printf("=== Задание 1 ===\n");
    printf("F1(x) = x^2 - 3x + 9, если x <= 3;  1 / (x^3 + 3), если x > 3\n");
    printf("F2(x) = x * e^(sin(x^2))\n");
    printf("Введите x: ");
    scanf("%lf", &x);

    f1 = fa(x);
    f2 = fb(x);

    /* п.2 - значения функций */
    printf("fa(x) = %lf, fb(x) = %lf\n", f1, f2);

    /* п.3 - произведение, разность квадратов, удвоенная сумма */
    printf("произведение = %lf, разность квадратов = %lf, удвоенная сумма = %lf\n\n",
        product(f1, f2), diff_squares(f1, f2), double_sum(f1, f2));

    /* п.4 - меню */
    do
    {
        printf("Меню:\n");
        printf("1 - значение F1(x)\n");
        printf("2 - значение F2(x)\n");
        printf("3 - произведение F1(x) * F2(x)\n");
        printf("4 - разность квадратов F1(x)^2 - F2(x)^2\n");
        printf("5 - удвоенная сумма 2 * (F1(x) + F2(x))\n");
        printf("0 - выход из меню\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 5)
        {
            printf("Введите x: ");
            scanf("%lf", &x);
            f1 = fa(x);
            f2 = fb(x);
        }

        switch (choice)
        {
        case 1:
            res = f1;
            printf("F1(%.4lf) = %lf\n\n", x, res);
            break;
        case 2:
            res = f2;
            printf("F2(%.4lf) = %lf\n\n", x, res);
            break;
        case 3:
            res = product(f1, f2);
            printf("Произведение = %lf\n\n", res);
            break;
        case 4:
            res = diff_squares(f1, f2);
            printf("Разность квадратов = %lf\n\n", res);
            break;
        case 5:
            res = double_sum(f1, f2);
            printf("Удвоенная сумма = %lf\n\n", res);
            break;
        case 0:
            printf("Выход из меню\n\n");
            break;
        default:
            printf("Неизвестный пункт меню\n\n");
            break;
        }
    } while (choice != 0);

    /* Задание 2. sin(x) тремя способами */
    printf("=== Задание 2. sin(x) ===\n");
    printf("Введите x (в радианах): ");
    scanf("%lf", &x);
    printf("Введите число членов ряда N: ");
    scanf("%d", &N);
    printf("Введите точность eps: ");
    scanf("%lf", &eps);

    if (N < 1 || eps <= 0)
        printf("Ошибка: N должно быть >= 1, eps > 0\n\n");
    else
    {
        s_std = sin(x);

        printf("\n  N |    sin_N     |  отклонение\n");
        printf("----+--------------+--------------\n");
        for (i = 1; i <= N; i++)
        {
            s_n = sin_n(x, i);
            printf("%3d | %12.8lf | %+.4e\n", i, s_n, s_n - s_std);
        }

        s_eps = sin_eps(x, eps);
        printf("\nСтандартная sin(x)  = %.10lf\n", s_std);
        printf("Ряд по N = %d       = %.10lf, отклонение %+.4e\n",
            N, sin_n(x, N), sin_n(x, N) - s_std);
        printf("Ряд по eps = %g = %.10lf, отклонение %+.4e\n\n",
            eps, s_eps, s_eps - s_std);
    }

    /* Задание 2 (вариант 1). e^(-x) через ряд */
    printf("=== Задание 2. Вариант 1: e^(-x) ===\n");
    printf("e^(-x) = 1 - x + x^2/2! - x^3/3! + ...\n");
    printf("Введите x: ");
    scanf("%lf", &x);
    printf("Введите число членов ряда N: ");
    scanf("%d", &N);
    printf("Введите точность eps: ");
    scanf("%lf", &eps);

    if (N < 1 || eps <= 0)
    printf("Ошибка: N должно быть >= 1, eps > 0\n");
    else
    {
        e_std = exp(-x);

        printf("\n  N |   exp_N      |  отклонение\n");
        printf("----+--------------+--------------\n");
        for (i = 1; i <= N; i++)
        {
            e_n = exp_neg_n(x, i);
            printf("%3d | %12.8lf | %+.4e\n", i, e_n, e_n - e_std);
        }

        e_eps = exp_neg_eps(x, eps);
        printf("\nСтандартная exp(-x) = %.10lf\n", e_std);
        printf("Ряд по N = %d       = %.10lf, отклонение %+.4e\n",
            N, exp_neg_n(x, N), exp_neg_n(x, N) - e_std);
        printf("Ряд по eps = %g = %.10lf, отклонение %+.4e\n",
            eps, e_eps, e_eps - e_std);
    }

    return 0;
}

/* F1(x): кусочная функция */
double fa(double x)
{
    double y;
    if (x <= 3)
        y = x * x - 3 * x + 9;
    else
        y = 1.0 / (x * x * x + 3);
    return y;
}

/* F2(x) = x * e^(sin(x^2)) */
double fb(double x)
{
    double y;
    y = x * exp(sin(x * x));
    return y;
}

/* Произведение значений */
double product(double a, double b)
{
    double r;
    r = a * b;
    return r;
}

/* Разность квадратов значений */
double diff_squares(double a, double b)
{
    double r;
    r = a * a - b * b;
    return r;
}

/* Удвоенная сумма значений */
double double_sum(double a, double b)
{
    double r;
    r = 2 * (a + b);
    return r;
}

double sin_n(double x, int N)
{
    double sum = 0, term = x;
    int k;

    for (k = 1; k <= N; k++)
    {
        sum += term;
        term *= -x * x / ((2 * k) * (2 * k + 1));
    }
    return sum;
}

double sin_eps(double x, double eps)
{
    double sum = 0, term = x;
    int k = 1;

    while (fabs(term) >= eps)
    {
        sum += term;
        term *= -x * x / ((2 * k) * (2 * k + 1));
        k++;
    }
    return sum;
}

double exp_neg_n(double x, int N)
{
    double sum = 0, term = 1;
    int n;

    for (n = 0; n < N; n++)
    {
        sum += term;
        term *= -x / (n + 1);
    }
    return sum;
}

double exp_neg_eps(double x, double eps)
{
    double sum = 0, term = 1;
    int n = 0;

    while (fabs(term) >= eps)
    {
        sum += term;
        term *= -x / (n + 1);
        n++;
    }
    return sum;
}
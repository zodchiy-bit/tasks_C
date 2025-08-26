/*

TASK:

Подвиг 8. Объявите в программе структуру с полями x, y типа int и определите для нее тип POINT. Объявите функцию с именем get_means и двумя параметрами (порядок важен):

одномерным массивом структур POINT;
длиной (числом элементов) этого массива (тип size_t).
Функция get_means должна вычислять два средних арифметических числа: отдельно для первой координаты x и отдельно для второй координаты y. Вычисленные вещественные значения сохранить в структуре типа DATA (объявить до функции), которая содержит два поля: mean_x и mean_y типа double. Функция get_means должна возвращать сформированную структуру DATA.

В функции main объявите массив points структур POINT длиной 20 элементов. Прочитайте из входного потока целые числа x0, y0, x1, y1, ..., записанные в одну строчку через пробел. Максимальное число пар чисел не превышает 20, но может быть и меньше. Вызовите функцию get_means для вычисления средних только для актуальных элементов массива points (тех, в которых хранятся данные из входного потока, а не все 20). Возвращенные значения вывести в консоль в одну строчку через пробел с точностью до сотых.

*/

#include <stdio.h>

typedef struct
{
    int x, y;
} POINT;

typedef struct
{
    double mean_x, mean_y;
} DATA;

DATA get_means(POINT arr[], size_t len)
{
    double average_x, average_y;

    for (int i = 0; i < len; ++i)
    {
        average_x += arr[i].x;
        average_y += arr[i].y;
    }

    average_x /= (double)len;
    average_y /= (double)len;

    return (DATA){average_x, average_y};
}

int main(void)
{
    size_t count = 0;
    POINT points[20] = {0};

    while ((scanf("%d %d", &points[count].x, &points[count].y) == 2))
    {
        count++;
    }

    DATA data = get_means(points, count);
    printf("%.2lf %.2lf\n", data.mean_x, data.mean_y);
    return 0;
}

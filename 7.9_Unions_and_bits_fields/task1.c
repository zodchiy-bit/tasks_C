/*

TASK:

Подвиг 4. Объявите в программе перечисление с именем типа TYPE_COORD и константами coord_int, coord_double со значениями 1 и 2 соответственно. Объявите в программе объединение с именем типа COORD и полями:

coord_i (тип int);
coord_d (тип double).
Объявите в программе структуру с именем типа POINT2 и полями:

x, y (тип COORD);
type (тип TYPE_COORD).
В функции main создайте переменную с именем pt типа POINT2. Прочитайте из входного потока данные в следующем формате:

<тип данных, целое число> <координата x> <координата y>

Если первое значение (тип данных) равно 1, то следующие координаты x, y - целочисленные (константа coord_int), иначе - вещественные (константа coord_double). Занесите в переменную pt прочитанные значения в соответствии с их типами. Не забудьте присвоить нужное значение полю type переменной pt.

P. S. В консоль ничего выводить не нужно.
*/

#include <stdio.h>

typedef enum
{
    coord_int,
    coord_double
} TYPE_COORD;

typedef union
{
    int coord_i;
    double coord_d;
} COORD;

typedef struct
{
    COORD x, y;
    TYPE_COORD type;
} POINT2;

int main(void)
{
    POINT2 pt;
    int type;
    scanf("%d", &type);
    if (type == 1)
    {
        pt.type = coord_int;
        scanf("%d %d", &pt.x.coord_i, &pt.y.coord_i);
    }
    if (type == 2)
    {
        pt.type = coord_double;
        scanf("%lf %lf", &pt.x.coord_d, &pt.y.coord_d);
    }
    __ASSERT_TESTS__
    return 0;
}

/*
TASK:

Подвиг 2. Продолжите программу. Объявите структуру с идентификатором tag_geom и полями:

char type;  // тип геометрической фигуры
int x0, y0; // координаты верхнего левого угла
int x1, y1; // координаты нижнего правого угла

                  
В функции main объявите переменную geom структуры tag_geom и заполните поля следующими значениями:

type = 1; (x0, y0) = (10, 20); (x1, y1) = (50, 30).

Объявите в функции main указатель ptr_geom на переменную geom. С помощью указателя выведите в консоль значения полей переменной geom в виде целых чисел в одну строчку через пробел в порядке: type, x0, y0, x1, y1.
*/


#include <stdio.h>

struct tag_geom
{
    char type;
    int x0, y0;
    int x1, y1;
};

int main(void)
{
    struct tag_geom geom = {1, 10, 20, 50, 30};
    struct tag_geom *ptr_geom = &geom;
    printf("%d %d %d %d %d\n", ptr_geom->type, ptr_geom->x0, ptr_geom->y0, ptr_geom->x1, ptr_geom->y1);
   // __ASSERT_TESTS__
    return 0;
}

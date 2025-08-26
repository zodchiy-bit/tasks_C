/*
TASK:

Подвиг 3. Продолжите программу. Объявите структуру с идентификатором tag_rub и полями:

double ratio_usd;  // курс доллара к рублю (1$ = xx рублей)
int rubs; // количество рублей

                  
В функции main объявите указатель account_r структуры tag_rub и выделите память под структуру tag_rub (указатель account_r должен ссылаться на выделенную область памяти). Затем, через указатель account_r значение ratio_usd установите равным 91.32, а значение rubs прочитайте из входного потока.

Вычислите количество долларов на счете в соответствии с курсом ratio_usd. Выведите в консоль полученное значение в виде вещественного числа с точностью до сотых.

P. S. Не забудьте в конце (после __ASSERT_TESTS__) освободить память.
*/

#include <stdio.h>
#include <stdlib.h>

struct tag_rub
{
    double ratio_usd;
    int rubs;
};

int main(void)
{
    struct tag_rub *account_r = malloc(sizeof(struct tag_rub));
    account_r->ratio_usd = 91.32;
    if (scanf("%d", &account_r->rubs) != 1)
    {
        printf("Input error\n");
        return 0;
    }

    printf("%.2lf\n", (double)account_r->rubs / account_r->ratio_usd);
   // __ASSERT_TESTS__
    free(account_r);
    return 0;
}

/*

TASK :

Подвиг 9 (с повторением). Объявите структуру с полями:

fname: строка максимальной длиной 100 символов (фамилия);
old: целое число (тип int); возраст;
stag: целое число (тип int); стаж;
salary; целое число (тип int); зарплата;
efs; вещественное число (тип double); эффективность труда сотрудника
Определите для этой структуры тип PERSON. 

Объявите функцию с именем fill_data, которая ничего не возвращает и первые два параметра (порядок важен) - это указатель на структуру PERSON и форматная строка. Следующие параметры вариадические (то есть, функция принимает произвольное число параметров). Форматная строка определяет данные, которые записываются в указанную структуру PERSON, а также набор и порядок следования вариадических данных. Форматная строка может включать следующие символы:

#f - строка с фамилией;
#o - возраст;
#g - стаж;
#s - зарплата;
#e - эффективность сотрудника.

Например:

"#f #e#s, #o"

соответствует вариадическим параметрам с типами данных:

char*, double, int, char

То есть, в форматной строке достаточно выделять спецификаторы #<символ> и их порядок, остальные символы форматной строки значения не имеют.

В функции main вызовите функцию fill_data с передачей в нее всех необходимых аргументов (значения придумайте сами) и следующей форматной строкой:

"#o #e #s #f"

P. S. В консоль ничего выводить не нужно.

*/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

typedef struct
{
    char fname[100];
    int old;
    int stag;
    int salary;
    double efs;
} PERSON;

void fill_data(PERSON *ptr, const char *format, ...)
{
    va_list arg;
    va_start(arg, format);

    for (int i = 0; format[i] != '\0'; ++i)
    {
        if (format[i] == '#')
        {
            i++;
            switch (format[i])
            {
            case 'f':
            {
                char *str = va_arg(arg, char *);
                strncpy(ptr->fname, str, sizeof(ptr->fname) - 1);
                ptr->fname[sizeof(ptr->fname) - 1] = '\0';
                break;
            }
            case 'o':
            {
                ptr->old = va_arg(arg, int);
                break;
            }
            case 'g':
            {
                ptr->stag = va_arg(arg, int);
                break;
            }
            case 's':
            {
                ptr->salary = va_arg(arg, int);
                break;
            }
            case 'e':
            {
                ptr->efs = va_arg(arg, double);
                break;
            }
            default:
                break;
            }
        }
    }
    va_end(arg);
}

int main(void)
{
    PERSON p;
    fill_data(&p,
              "#o #e #s #f",
              26,
              0.99,
              100000,
              "Stetsyuk");
    return 0;
}

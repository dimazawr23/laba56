#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include "discriminant.h"
#include "computering_roots.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c, x1, x2;
	short fl = 5;
	printf("Введите аргументы: a, b, c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	if (a == 0)
		printf("Нет решения!\n");
	else
		fl = computering_roots(a, b, c, &x1, &x2);
	if (fl == 0)
		printf("Нет реальных корней!\n");
	if (fl == 1)
		printf("Только один корень: x = %4.2f\n", x1);
	if (fl == 2)
		printf("Два корня: x1 = %4.2f; x2 = %4.2f\n", x1, x2);
	return 0;
}

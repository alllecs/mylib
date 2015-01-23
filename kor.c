/* Лабораторная работа № 3 [Ссылка]( http://bigor.bmstu.ru/?cnt/?doc=OP2/lab3new.aux/?cou=OP2/OP_P.cou ) */

#include <stdio.h>
#include <math.h>

int main(void)
{
	int ret;
	int a;
	double b;

	printf("Введите число\n");
	ret = scanf("%d", &a);

	if (ret != 1)
		return 2;

	if (a < 0) {
		printf("Указано отрицательное число\n");
		return 1;
	}

	b = sqrt(a);
	printf("%.2f\n", b);

	return 0;
}

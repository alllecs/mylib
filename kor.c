/* Лабораторная работа № 3 [Ссылка]( http://bigor.bmstu.ru/?cnt/?doc=OP2/lab3new.aux/?cou=OP2/OP_P.cou ) */

#include <stdio.h>
#include <math.h>

int main(void)
{
	int ret;
	double a, b, c, D;
	double x1, x2;
	printf("Уравнение a*x^2 + b*x + c = 0\n");
	printf("Введите коэффициент 'a'\n");
	ret = scanf("%lf", &a);

	if (ret != 1)
		return 2;

	printf("Введите коэффициент 'b'\n");
	ret = scanf("%lf", &b);

	if (ret != 1)
		return 2;

	printf("Введите коэффициент 'c'\n");
	ret = scanf("%lf", &c);

	if (ret != 1)
		return 2;

	D = pow(b,2) - (4 * a * c);
	if (D < 0) {
		printf("Нет действительных корней уравнения\n");
		return 3;
	}
	if (D == 0) {
		x1 = ((- b) + sqrt(D)) / (2 * a);
		printf("Один корень уравнения %.2f\n", x1);
		return 4;
	}
	if (D > 0) {
		x1 = ((- b) + sqrt(D)) / (2 * a);
		x2 = ((- b) - sqrt(D)) / (2 * a);
		printf("Первый корень уравнения %.2f,"
			" второй корень уравнения %.2f\n",
			x1, x2);
		return 5;
	}
	return 0;
}

#include <stdio.h>
#include <math.h>

double f(double x)
{
	return (x - exp(-x));
}

double del(double a, double b, double e)
{
	double c;
	if (f(a) > 0 || f(b) < 0) {
		printf("Значения функции на концах отрезка одинакового знака\n");
		return 0;
	}

	while (f(fabs((a + b) / 2)) > e) {
		c = (a + b) / 2;
		if (f(c) < 0) {
			a = c;
		} else {
			b = c;
		}
	}

	return c;
}

void main()
{
	double x, e;
/*	int a, b;
	printf("Введите левую границу отрезка (а) = ");
	scanf("%d", &a);
	printf("Введите правую границу отрезка (b) = ");
	scanf("%d", &b);
*/	printf("Введите точность = ");
	scanf("lf", &e);

	x = del(-1, 3, e);
	printf("x = %lf\n", f(x));

}

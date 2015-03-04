#include <stdio.h>
#include <math.h>

double f1(double x)
{
	return (x - exp(-x));
}

double f(double x)
{
	return (-x);
}


double del(double a, double b, double e)
{
	double c;


	while (fabs(f((a + b) / 2)) > e) {
		c = (a + b) / 2;
		if (f(c) < 0) {
			a = c;
		} else {
			b = c;
		}
	}

	return c;
}

void main(void)
{
	double x, e;
	double a, b;
	printf("Введите левую границу отрезка (а) = ");
	scanf("%lf", &a);
	printf("Введите правую границу отрезка (b) = ");
	scanf("%lf", &b);
	printf("Введите точность = ");
	scanf("%lf", &e);

	if ((f(a) * f(b)) > 0) {
		printf("Границы отрезка одинакового знака\n");
		return;
	}
	x = del(a, b, e);
	printf("x = %lf\n", f(x));

}

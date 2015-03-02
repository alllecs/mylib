#include <stdio.h>
#include <math.h>

double f(double x)
{
	return (x - exp(-x));
}

double del(double a, double b, double c)
{
	double k;

	while (fabs(b - a) > c) {
		k = (a + b) / 2;
		if ((f(a) * f(b)) < 0) {
			b = k;
		} else {
			a = k;
		}
	}

	return k;
}

void main()
{
	double x, c;
	printf("Введите точность = ");
	scanf("lf", &c);
	x = del(-3.123, 4.234, c);
	printf("x = %lf\n", f(x));

}

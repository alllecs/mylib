#include <stdio.h>
#include <math.h>

double f(double x)
{
	return (x - exp(-x));
}
void main()
{
	double i;
	double a, b;

	printf("Введите границу отрезка a = ");
	scanf("%lf", &a);
	printf("Введите границу отрезка b = ");
	scanf("%lf", &b);

	printf("Значение функции");
	printf("\tЧисло на отрезке \n");

	for (i = a; i < b; i++) {
		printf("%lf", f(i));
		printf("\t\t\t%0.1lf\n", i);
	}

}

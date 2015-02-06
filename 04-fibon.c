#define DEBUG

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fibon(int n)
{
	int k;
	int m = 1;
	int i = 1;
	int j = 1;

	while (m < n) {
		k = i + j;
		i = j;
		j = k;
		m += 1;
	}
	return i;
}

int main(int argc, char *argv[])
{
	int i;
	double eps;
	double f_pr = 0;
	double dif;

	if (argc != 2) {
		printf("Отсутствует аргумент или указано больше 1 аргумента\n");
		return 1;
	}

	sscanf(argv[1], "%lf", &eps);

	if (eps < 0.0001 || eps > 0.1) {
		printf("Ошибка ввода погрешности\n");
		return 2;
	}

	for (i = 1; i < 30; i++) {
		double f;
		f = (double)fibon(i) / (double)fibon(i - 1);
#ifdef DEBUG
		printf("fib_%d = %d, fib_%d = %d, f = %.12f, f - f_pr =%.12f\n",
			i, fibon(i),
			i - 1, fibon(i - 1),
			f, fabs(f - f_pr));
#endif
		dif = fabs(f - f_pr);
		if (dif <= eps && dif > 0) {
			printf("Предел последовательности = %lf\n", f);
			return 0;
		}

		f_pr = f;
	}

	return 2;
}

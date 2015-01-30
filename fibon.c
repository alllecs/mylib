#include <stdio.h>
#include <stdlib.h>

int f1(int n)
{
	int sum;

	printf("f1: entrance: n=%d\n", n);

	if (n <= 0)
		return 0;

	sum = f1(n - 1) + n;
	printf("f1: exit: n=%d, sum=%d\n", n, sum);

	return sum;
}

int fibonr(int n)
{
	if (n < 0) {
		printf("Введено отрицательное число\n");
		return 4;
	}
	if (n == 0) {
		printf("Введите число больше 0\n");
		return 3;
	}
	if (n == 1)
		return 1;

	if (n == 2)
		return 1;

	return (fibonr(n - 1) + fibonr(n - 2));
}

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
/*
double gold(double eps)
{
	return ...;
}
*/
int main(int argc, char *argv[])
{
//	int n;
//	int ret;
//	int m = 0;
//	double f, p;

	if (argc != 2) {
		printf("Отсутствует или указано больше 1 аргумента\n");
		return 1;
	}
#if 0
	ret = sscanf(argv[1], "%d", &n);

	if (ret != 1)
		return 2;



	if (n > 45) {
		printf("При n > 45 возможно переполнение\n");
		return 5;
	}

	printf("%d\n", fibon(n));

	while (m < n) {
	f = (double)fibon(n - 1) / (double) fibon(n - 2);
	printf("f-1 = %d, f-2 = %d, f1/f2 = %.4f\n", fibon(n - 1), fibon(n - 2), f);
	m += 1;
	}


#endif
	int i;
	double p;

	sscanf(argv[1], "%lf", &p);

	for (i = 1; i < 30; i++) {
		double f;
		double e, d;

		f = (double)fibon(i) / (double)fibon(i - 1);
//		printf("f_%d = %d, f_%d = %d, f1/f2 = %.12f\n",
//			i, fibon(i),
//			i - 1, fibon(i - 1),
//			f);
		e = (double)fibon(i - 1) / (double)fibon(i - 2);
		printf("x_%d = %.12f\n", i, f);
		d = f - e;
		printf("%f\n", d);
		if (d < 0) {
			d = d * (- 1);
		}
		if (d <= p && d > 0) {
			printf("Найден предел последовательности\n");
			return 1;
		}
	}


	return 0;
}

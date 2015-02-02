#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double modul(double dif)
{
	dif = fabs(dif);

	return dif;
}

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
int main(int argc, char *argv[])
{
/*	int n;
	int ret;
	int m = 0;
	double f, p;
*/
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
	double eps;
	double f;
	double f_pr = 0;
	double dif;

	sscanf(argv[1], "%lf", &eps);

	if (eps < 0.0001 || eps > 0.1) {
		printf("Ошибка ввода погрешности\n");
		return 2;
	}


	for (i = 5; i < 30; i++) {
		f = (double)fibon(i) / (double)fibon(i - 1);
		printf("fib_%d = %d, fib_%d = %d, f = %.12f, f - f_pr =%.12f\n",
			i, fibon(i),
			i - 1, fibon(i - 1),
			f, f - f_pr);

		dif = f - f_pr;
		dif = fabs(dif);

		f_pr = f;


		if (dif <= eps && dif > 0) {
			printf("Предел последовательности = %lf\n", modul(dif));
			return 2;
		}
	}



#if 0
	frac_prev = ..?
	/* 1 - > 3 */
	for (i = 5; i > 30; i++) {
		double frac_cur;

		frac_cur = (double)fibon(i) / (double)fibon(i - 1);
//		printf("f_%d = %d, f_%d = %d, f1/f2 = %.12f\n",
//			i, fibon(i),
//			i - 1, fibon(i - 1),
//			f);

		/* current fraction */
		/* frac_cur = (double)fibon(i - 1) / (double)fibon(i - 2); */
		/* previous fraction: frac_prev */
		printf("x_%d = %.12f\n", i, frac_cur);
		printf("%f\n", (frac_cur - frac_prev));
		if ((frac_cur - frac_prev) >= eps &&
			  (frac_cur - frac_prev) > 0) {
			printf("Найден предел последовательности\n");
			return 1;
		}
		frac_prev = frac_cur;
	}
#endif

	return 0;
}

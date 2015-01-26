#include <stdio.h>

int main(void)
{
	int n, m;
	int ret;
	double i, j, k, f;

	printf("Введите номер члена ряда Фибоначчи\n");
	ret = scanf("%d", &n);

	if (ret != 1)
		return 2;

	if (n < 0) {
		printf("Введено отрицательное число\n");
		return 3;
	}

	j = 1;
	i = 1;
	m = 1;
	while (m < n) {
		f = j / i;
		k = i + j;
		i = j;
		j = k;
		m += 1;
	}
	printf("%.0f\n", i);
	printf("%.3f\n", (j / i));
	printf("%.6f\n", (f - (j / i)));

	return 0;
}

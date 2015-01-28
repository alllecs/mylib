#include <stdio.h>
#include <stdlib.h>

int fibonr(int n)
{
	if (n == 1)
		return (n = 1);
	if (n == 2)
		return (n = 1);

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
	int n;
	int ret;

	if (argc != 2) {
		printf("Отсутствует или указано больше 1 аргумента\n");
		return 4;
	}

	ret = sscanf(argv[1], "%d", &n);

	if (ret != 1)
		return 2;

	if (n < 0) {
		printf("Введено отрицательное число\n");
		return 3;
	}

	printf("%d\n", fibonr(n));

	return 0;
}

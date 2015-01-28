#include <stdio.h>
#include <stdlib.h>

int fibon(int n)
{
	int m;
	double k;
	int i;
	double j;

	j = 1;
	i = 1;
	m = 1;
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

	if (argc != 2) {
		printf("Отсутствует или указано больше 1 аргумента\n");
		return 4;
	}

	sscanf(argv[1], "%d", &n);

	if (n < 0) {
		printf("Введено отрицательное число\n");
		return 3;
	}

	printf("%d\n", fibon(n));

	return 0;
}

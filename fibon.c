#include <stdio.h>

int fibon(char n)
{
	int m;
	double k;
	int i;
	double j;

	j = 1;
	i = 1;
	m = 1;
	while (m < n) {
//		f = j / i;
		k = i + j;
		i = j;
		j = k;
		k = j / i;
		m += 1;
	}
	return i;
}

int main(int argc, char *argv[])
{
	char n;

	n = argv[1];
	if (n < 0) {
		printf("Введено отрицательное число\n");
		return 3;
	}

	printf("%d\n", fibon(n));
//	printf("%.3f\n", k);
//	printf("%.6f\n", (f - k));

	return 0;
}

#include <stdio.h>
#include <math.h>

#define INT_SIZE 99

int main(int argc, char *argv[])
{
	int system, numb, rest;
	int i = 0;
	int k;
	int mass[99];
	double binnumb, bin;
	double x;

	if (argc == 2)
		sscanf(argv[1], "%lf", &binnumb);

	if (argc != 2) {
		printf("Введите десятичное число\n");
		scanf("%lf", &binnumb);

		printf("Введите систему счисления\n");
		scanf("%d", &system);

		if (system < 2 || system > 16) {
			printf("Неправильно введена система счисления\n");
			return 3;
		}
	}

	numb = (int)binnumb;
	bin = binnumb - (int)binnumb;

	if (numb >= 1) {
		while (numb > 0) {
			rest = numb % system;
			numb = numb / system;
			mass[i++] = rest;
		}
	}
	for (k = i - 1; k > - 1; k--) {
		printf("%X", mass[k]);
	}
	printf(".");

	i = 0;

	if (bin < 1 && bin > 0) {
		rest = 0;
		x = 1;
		while (x > 0.0001) {
			x = x / 2;
			if (bin >= x) {
				bin = bin - x;
				rest = 1;
			} else
				rest = 0;
			mass[i++] = rest;
		}
#if 0
		while (bin > 0.0001) {
			if (bin >= 0.5) {
				bin = bin - 0.5;
				rest = 1;
			} else
				rest = 0;
			mass[i++] = rest;

			if (bin >= 0.25) {
				bin = bin - 0.25;
				rest = 1;
			} else
				rest = 0;
			mass[i++] = rest;

			if (bin >= 0.125) {
				bin = bin - 0.125;
				rest = 1;
			} else
				rest = 0;
			mass[i++] = rest;
			break;
		}
#endif
		for (i = 0; i < 3; i++) {
			printf("%X", mass[i]);
		}
	}

	printf("\n");
	return 0;
}

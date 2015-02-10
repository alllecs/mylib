#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 99

int main(int argc, char *argv[])
{
	int system, numb, rest;
	int i = 0;
	int k;
	int mass[N];
	double binnumb, bin;
	double x;

	if (argc >= 2 || argc <= 4)
		sscanf(argv[1], "%lf", &binnumb);
		sscanf(argv[2], "%d", &system);


	if (argc < 2 || argc > 4) {
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

	if (bin < 1 && bin > 0 && system == 2) {
		i = 0;
		rest = 0;
		printf(".");
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

		for (i = 0; i < 3; i++) {
			printf("%X", mass[i]);
		}
	}

	if (bin < 1 && bin > 0 && system == 10) {
		i = 0;
		rest = 0;
		printf(".");
		x = 1;
		while (x > 0.0001) {
			x = x / 10;
			if (bin != 0) {
				bin = bin * 10;
				rest = (int)bin;
				bin = bin - (int)bin;
			} else
				rest = 0;
			mass[i++] = rest;
		}

		for (i = 0; i < 3; i++) {
			printf("%X", mass[i]);
		}
	}

	printf("\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define COMMANDS 8

unsigned int array[COMMANDS][COMMANDS];

int array_my(unsigned int *array)
{
	int i, j;

	printf("------\n");
	for (i = 0; i < COMMANDS; i++) {
		for (j = 0; j < COMMANDS; j++) {
			printf("%d\t", array[i * COMMANDS + j]);
		}
		printf("\n");
	}
}

int rand_my(int a)
{
	a = rand() % 3;
	if(a == 2) {
		a = 3;
	}
	return a;
}

void tab(int a)
{
	int i, j;

	a = 0;
	for (i = 0; i < COMMANDS; i++) {
		for (j = 0; j < COMMANDS; j++) {

			if (j < i) {

				a = rand_my(a);
				if (a == 1) {
					array[i][j] = a;
					array[j][i] = a;
				}
				if (a == 3) {
					array[i][j] = a;
					array[j][i] = 0;
				}
				if (a == 0) {
					array[i][j] = a;
					array[j][i] = 3;
				}
			}

			if (i == j) {
				array[i][j] = 0;
			}

		}
	}
}


int main(void)
{
	int i, j;
	int sum;
	int a;
	char max[COMMANDS];

	array_my(&array[0][0]);

	a = 0;
	tab(a);
	array_my(&array[0][0]);
	for (i = 0; i < COMMANDS; i++) {
		sum = 0;
		for (j = 0; j < COMMANDS; j++) {
			sum = sum + array[i][j];
		}
		printf("Команда %d набрала %d очков\n", i + 1, sum);
		if (sum == 3 * COMMANDS) {
			printf("Команда %d набрала максимальное число очков\n", i+1);
		}
	}
	printf("Максимальное возможное число очков = %d\n", 3 * COMMANDS);
}

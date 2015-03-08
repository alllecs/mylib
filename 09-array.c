#include <stdio.h>
#include <stdlib.h>

#define COMMANDS 8

unsigned int array[COMMANDS][COMMANDS];

void rand_my(int a)
{
	a = rand();
	if(a == 2) {
		a = 3;
	}
	return a;
}

void tab(int a)
{
	int i, j;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (i == j) {
				array[i][j] = 0;
			}
			if (rand_my(a) == 1) {
				array[i][j] = rand_my(a);
				array[j][i] = rand_my(a);
			}
			if (rand_my(a) == 3) {
				array[i][j] = rand_my(a);
				array[j][i] = 0;
			}
			if (rand_my(a) == 0) {
				array[i][j] = rand_my(a);
				array[j][i] = 3;
			}
			printf("%d", array[i][j]);
	}
}


void main(void)
{
	int i, j;
	int sum;
	int a;

	sum = 0;
	tab(a);
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			sum = sum + array[i][j];
		}
		printf("Команда %d набрала %d очков\n", i, sum);
	}

}

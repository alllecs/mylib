#include <stdio.h>
#include <stdlib.h>

#define COMMANDS 8

unsigned int array[COMMANDS][COMMANDS];

char *cmd_name[] = {
	"Spartak",
	"Dinamo",
	"Zenit",
	"Chelsie",
	"Spartak-Paris",
	"Dinamo-Berlin",
	"Zenit-Amsterdam",
	"Loko",
};

#if (COMMANDS > 8)
#error "too many commands"
#endif

char *point(int i)
{

	if (i < 10 || i > 20) {
		switch (i % 10) {
			case 1:
				return "очко";
			case 2:
			case 3:
			case 4:
				return "очка";
		}
	}
	return "очков";
}


int array_my(unsigned int *array)
{
	int i, j;

	for (i = 0; i < COMMANDS; i++) {
		printf("%-10s\t", cmd_name[i]);
		for (j = 0; j < COMMANDS; j++) {
			printf("%-4d\t", array[i * COMMANDS + j]);
		}
		printf("\n");
	}
	return 0;
}

int rand_my(int a)
{
	a = rand() % 3;
	if(a == 2) {
		a = 3;
	}
	return a;
}

void tab()
{
	int i, j, a;

	a = 0;

	for (i = 0; i < COMMANDS; i++) {
		for (j = 0; j < COMMANDS; j++) {

			if (i == j) {
				array[i][j] = 0;
				break;
			}

			a = rand_my(a);
			switch (a) {
				case 1:
					array[i][j] = a;
					array[j][i] = a;
				break;
				case 3:
					array[i][j] = a;
					array[j][i] = 0;
				break;
				case 0:
					array[i][j] = a;
					array[j][i] = 3;
				break;
				default:
					printf("Ошибка\n");
				break;

			}
		}
	}
}


int main(void)
{
	int i, j;
	int sum;
	int a;
	char max[10];

	a = 0;
	tab(a);
	array_my(&array[0][0]);
	for (i = 0; i < COMMANDS; i++) {
		sum = 0;
		for (j = 0; j < COMMANDS; j++) {
			sum = sum + array[i][j];
		}
		printf("Команда %s набрала %d %s\n", cmd_name[i], sum, point(sum));
		if (sum == 3 * (COMMANDS - 1)) {
			printf("Команда %s набрала максимальное число очков\n", cmd_name[i]);
		}
		max[i] = sum;
	}
	printf("Максимальное возможное число очков = %d\n", 3 * (COMMANDS - 1));

	for (i = 0; i < 7; i++) {
		if (max[i] > sum) {
			sum = max[i];
			printf("Победитель %s, набрал %d очков\n", cmd_name[i], sum);
		} else {
			sum = sum;
		}
	}

	return 0;
}

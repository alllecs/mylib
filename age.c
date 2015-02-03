#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char *age(int i)
{
	switch (i % 10) {
		case 1:
			return "год";
		case 2:
		case 3:
		case 4:
			return "года";
	}
	return "лет";
}

int main(int argc, char *argv[])
{
	int i;
	int x, y;
	const int sov = 18;
	const int pen = 60;

	if (argc == 2)
		sscanf(argv[1], "%d", &i);

	if (argc != 2) {
		printf("Введите возраст\n");
		scanf("%d", &i);
	}



	if (i < 1 || i > 100) {
		printf("Неправильно указан возраст\n");
		return 3;
	}

	printf("Ваш возраст %d %s\n", i, age(i));

	x = abs(i - sov);

	if (i == sov)
		printf("Вы совершеннолетний\n");
	else {
		if (i < sov) {
			printf("Вам до совершеннолетия ");
		}
		if (i > sov) {
			printf("Вы совершеннолетний ");
		}
		printf("%d %s\n", x, age(x));
	}

	y = abs(i - pen);
	if (i == pen)
		printf("Вы пенсионер\n");
	else {
		if (i < pen) {
			printf("Вам до пенсии ");
		}
		if (i > pen) {
			printf("Вы на пенсии ");
		}
			printf("%d %s\n", y, age(y));
	}
	return 0;
}

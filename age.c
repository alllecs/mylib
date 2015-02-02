#include <stdio.h>
#include <math.h>

char *age(int i)
{
	switch (i % 10) {
		case 1:
			return"год";
		case 2:
		case 3:
		case 4:
			return"года";
	}
	return"лет";
}

int main(void)
{
	int i;
	int x, y;

	printf("Введите возраст\n");
	scanf("%d", &i);

	if(i < 1 || i > 100) {
		printf("Неправильно указан возраст\n");
		return 3;
	}

	printf("Ваш возраст %d %s\n", i, age(i));

	x = fabs(i - 18);
	if (i < 18) {
		printf("Вам до совершеннолетия %d %s\n", x, age(x));
	}
	if (i > 18) {
		printf("Вы совершеннолетний %d %s\n", x, age(x));
	}
	if (i == 18)
		printf("Вы совершеннолетний\n");

	y = fabs(i - 60);
	if (i < 60) {
		printf("Вам до пенсии %d %s\n", y, age(y));
	}
	if (i > 60) {
		printf("Вы на пенсии %d %s\n", y, age(y));
	}
	if (i == 60)
		printf("Вы пенсионер\n");

	return 0;
}

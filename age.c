#include <stdio.h>

int age(int j)
{
	switch (j % 10) {
		case 1:
			printf(" год");
			break;
		case 2:
		case 3:
		case 4:
			printf(" года");
			break;
		default:
			printf(" лет");
			break;
	}
	return j;
}
/*
char *stra(int hz)
{
	if (hz > 1000)
		return "kHz";

	return "Hz";
}
*/
int main(void)
{
	int i;
	int j;
	int x, y;

//	printf("%s %s\n", stra(1001), stra(10));

	printf("Введите возраст\n");
	scanf("%d", &i);

	if(i < 1 || i > 100) {
		printf("Неправильно указан возраст\n");
		return 3;
	}

	j = i % 100;
	printf("Ваш возраст %d\n", age(j));


	if (i < 18) {
		x = 18 - i;
		j = x % 100;
		printf("Вам до совершеннолетия %d %c\n", x, age(j));
	}
	if (i > 18) {
		x = i - 18;
		j = x % 100;
		printf("Вы совершеннолетний %d %c\n", x, age(j));
	}
	if (i == 18)
		printf("Вы совершеннолетний\n");

	if (i < 60) {
		y = 60 - i;
		j = y % 100;
		printf("Вам до пенсии %d %c\n", y, age(j));
	}
	if (i > 60) {
		y = i - 60;
		j = y % 100;
		printf("Вы на пенсии %d %c\n", y, age(j));
	}
	if (i == 60)
		printf("Вы пенсионер\n");

	return 0;
}

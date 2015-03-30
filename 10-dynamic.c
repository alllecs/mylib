/*
 * Лабораторная работа 10. Динамические массивы
 * http://bigor.bmstu.ru/?cnt/?doc=OP2/lab10new.aux/?cou=OP2/OP_P.cou
 *
 * Разработайте программу, которая читает из стандартного потока ввода строки
 * и размещает их в динамических массивах строк.
 * Перед размещением из строки удаляются все символы-разделители (пробелы
 * и табуляция).
 * Адреса этих массивов запоминаются в массиве указателей.
 * После окончания ввода содержимое массивов выводится
 * в стандартный поток вывода.
 *
 * Максимальное количество строк 3.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STR 3
#define LINE 256

char *pointers[STR];

char *in(char *input1)
{
	int stl;
	int i;
	int c;
	char *input;
	char *x;

	stl = strlen(input1);

	input = (char *)malloc(stl + 1);
	bzero(input, stl + 1);
	x = &input[0];
	for (i = 0; i < stl && i < LINE; i++) {
		c = input1[i];
		if (c != ' ' && c != '\t') {
			*x = c;
			x++;
		}
	}
//	puts(input);
	return input;
//	free(input);
}

int main()
{
	char input1[LINE];
	int i;

	i = 0;
	while (i < STR) {
		fgets(input1, LINE, stdin);
		pointers[i] = in(input1);
//		printf("pointers[%d] = %p\n", i, pointers[i]);
		i++;
	}

	i = 0;
	while (i < STR) {
		printf("pointers[%d] = %s", i, pointers[i]);
		i++;
		free(pointers[i]);
	}

	return 0;
}

/* [Ссылка]
( http://bigor.bmstu.ru/?cnt/?doc=OP2/lab10new.aux/?cou=OP2/OP_P.cou )
Разработайте программу,
которая читает из стандартного потока ввода строки
и размещает их в динамических массивах строк.
Перед размещением из строки удаляются все символы-разделители
(пробелы и табуляция).
Адреса этих массивов запоминаются в массиве указателей.
После окончания ввода содержимое массивов выводится в стандартный поток вывода.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE 256

void in(char *input1)
{
	int stl;
	int i;
	int c;
	char *input;
	char *x;

	stl = strlen(input1);

	input = (char *)malloc(stl + 1);
	x = &input[0];

	bzero(input, sizeof(input));
	for (i = 0; i < stl && i < LINE; i++) {
		c = input1[i];
		if (c != ' ' && c != '\t') {
			*x = c;
			x++;
		}
	}
	puts(input);
}


void main()
{
	char input1[LINE];

	fgets(input1, LINE, stdin);
	in(input1);

}

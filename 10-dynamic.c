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

void main()
{
	int i;
	char input1[LINE];
	char c;
	char stl;
	char *x;

	x = &input1[0];

	fgets(input1, LINE, stdin);
	stl = strlen(input1);
	for (i = 0; i < stl && i < LINE; i++) {
		c = input1[i];
		if (c != ' ' && c != '\t') {
			*x = c;
			x++;
		}
	}

	*x = '\0';
	puts(input1);
}

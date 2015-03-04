#include <stdio.h>

const unsigned int i = 8;
const unsigned int j = 8;

int array[i][j] = {
{ 0, 0, 1, 3, 3, 0, 0, 1 },
{ 3, 0, 3, 1, 1, 1, 0, 3 },
{ 1, 0 ,0, 3, 0, 0, 0, 1 },
{ 0, 1, 0, 0, 3, 1, 0, 1 },
{ 0, 1, 3, 0, 0, 0, 1, 0 },
{ 3, 1, 3, 1, 3, 0, 1, 3 },
{ 3, 3, 3, 3, 1, 1, 0, 0 },
{ 1, 0, 1, 1, 3, 0, 3, 0 }
};

void main()
{
	int k = 0;
	i = 0;
	j = 0;
	while (i < 8) {
		while (j < 8) {
			k = array[i][j++];
		}
		printf("Команда k%d набрала всего %d очков\n", i, k);
		i++;
	}
}

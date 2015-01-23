#include <stdio.h>
#include <time.h>

int main(void)
{
	int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	time_t t;
	int days, mon, year;
	int hour, min, sec;
	int i, ret;

	t = time(NULL);

	if (t == -1)
		return 1;

	hour = (t / 3600 + 4) % 24;
	min = t % (60 * 60) / 60;
	sec = t % (60);
	printf("Time %02d:%02d:%02d\n", hour, min, sec);

	/* Enter days, month, year */
	printf("Enter year from 1970 to 2038:\n");
	ret = scanf("%d", &year);

	if (ret != 1)
		return 2;

	if (year < 1970 || year > 2038) {
		printf("Not correct enter year\n");
		return 3;
	}

	// Leap year
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		month[1] = 29;

	printf("Enter month:\n");
	ret = scanf("%d", &mon);

	if (ret != 1)
                return 2;

	if (mon < 1 || mon > 12) {
		printf("Not correct enter month\n");
		return 4;
	}

	printf("Enter day:\n");
	ret = scanf("%d", &days);

	if (ret != 1)
                return 2;


	if (days < 1 || days > month[mon - 1]) {
		printf("Not correct enter day\n");
		return 5;
	}


	for (i = 0; i < (mon - 1); i++)
		days += month[i];

	printf("Number day of the %d year = %d\n", year, days);

	return 0;
}

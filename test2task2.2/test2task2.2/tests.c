#include "Date.h"
#include <stdbool.h>

bool testForTask(void)
{
	Date* date = readFromFile("test.txt");
	int day = 0;
	int month = 0;
	int year = 0;
	getDate(date, &day, &month, &year);
	free(date);
	return (day == 16 && month == 5 && year == 2015);
}
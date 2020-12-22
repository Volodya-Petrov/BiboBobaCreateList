#include "tests.h"
#include "Date.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (!testForTask())
	{
		printf("Тесты провалены\n");
		return 1;
	}
	printf("Тесты пройдены успешно!\n");
	Date* date = readFromFile("task.txt");
	printDate(date);
	free(date);
}
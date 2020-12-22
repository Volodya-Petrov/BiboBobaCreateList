#include "Date.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	Date* date = readFromFile("task.txt");
	printDate(date);
	free(date);
}
#include "Date.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct Date
{
	int day;
	int month;
	int year;
} Date;

void datecpy(Date* destination, Date* source)
{
	destination->day = source->day;
	destination->month = source->month;
	destination->year = source->year;
}

void dateCompare(Date* maxDate, Date* currentDate)
{	
	if (currentDate->year < maxDate->year)
	{
		return;
	}
	if (currentDate->year > maxDate->year)
	{
		datecpy(maxDate, currentDate);
		return;
	}
	if (currentDate->month < maxDate->month)
	{
		return;
	}
	if (currentDate->month > maxDate->month)
	{
		datecpy(maxDate, currentDate);
		return;
	}
	if (currentDate->day < maxDate->day)
	{
		return;
	}
	datecpy(maxDate, currentDate);
}

Date* readFromFile(char fileName[])
{	
	Date* maxDate = calloc(1, sizeof(Date));
	if (maxDate == NULL)
	{
		return NULL;
	}
	Date* currentDate = calloc(1, sizeof(Date));
	if (currentDate == NULL)
	{
		free(maxDate);
		return NULL;
	}
	FILE* fileOpen = fopen(fileName, "r"); 
	while (fscanf(fileOpen, "%d.%d.%d", &(currentDate->day), &(currentDate->month), &(currentDate->year)) != EOF)
	{
		dateCompare(maxDate, currentDate);
	}
	free(currentDate);
	fclose(fileOpen);
	return maxDate;
}

void printDate(Date* date)
{
	printf("День: %i\n", date->day);
	printf("Месяц: %i\n", date->month);
	printf("Год: %i\n", date->year);
}
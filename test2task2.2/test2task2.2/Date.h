#pragma once

// структура даты
typedef struct Date Date;

// распечатать дату
void printDate(Date* date);

// считать дату с файла
Date* readFromFile(char fileName[]);

// выдает дату
void getDate(Date* date, int* day, int* month, int* year);
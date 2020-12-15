#include "quickSort.h"
#include "readData.h"
#include "../../Test2Task1/Test2Task1/List.h"
#include "transformData.h"
#include "../../Test2Task1/Test2Task1/testForList.h"
#include "testForTask.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void output(int array[], int size)
{	
	if (size < 1)
	{
		return;
	}
	int count = 1;
	for (int i = 0; i < size - 1; i++)
	{
		if (array[i] != array[i + 1])
		{
			printf("число - %i, количество - %i\n", array[i], count);
			count = 1;
		}
		else
		{
			count++;
		}
	}
	printf("число - %i, количество - %i", array[size - 1], count);
}

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (!testList())
	{
		printf("Тесты на списки провалены\n");
		return 1;
	}
	if (!testForTask())
	{
		printf("Тесты для задания провалены\n");
		return 1;
	}
	printf("Тесты пройдены успешно!\n");
	List* list = readData();
	int size = length(list);
	int* array = calloc(size, sizeof(int));
	transformToArray(array, list);
	quickSort(array, 0, size - 1);
	output(array, size);
	free(array);
	deleteList(&list);
}
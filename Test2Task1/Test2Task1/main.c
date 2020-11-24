#include "List.h"
#include "testForList.h"
#include "testForTask.h"
#include "reverseList.h"
#include "readFromFile.h"
#include <stdio.h>
#include <locale.h>

void printList(List* list)
{
	for (int i = 0; i < length(list); i++)
	{
		int value = 0;
		getValue(list, i, &value);
		printf("%i ", value);
	}
	printf("\n");
}

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (!testList())
	{
		printf("Тесты для списка провалены\n");
		return 1;
	}
	printf("Тесты для списка пройдены успешно!\n");
	if (testForTask())
	{
		printf("Тесты для задания провален\n");
		return 1;
	}
	printf("Тесты для задания пройдены успешно!\n");
	List* list = readFromFile("list.txt");
	List* newList = reverse(list);
	printList(list);
	printList(newList);
	deleteList(&list);
	deleteList(&newList);
}
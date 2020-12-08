#include "readFromFile.h"
#include "../../NewList/List/List.h"
#include "transformList.h"
#include "../../NewList/List/listTests.h"
#include <stdio.h>
#include <locale.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (!testList())
	{
		printf("Tests for list failed\n");
		return 1;
	}
	printf("Тесты пройдены успешно!\n");
	List* list = readFromFile("task.txt");
	list = removeDuplicates(list);
	for (int i = 0; i < length(list); i++)
	{
		printf("%s\n", getValue(list, i));
	}
	deleteList(&list);
}
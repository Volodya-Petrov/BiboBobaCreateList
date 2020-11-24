#include "testForTask.h"
#include "List.h"
#include "reverseList.h"
#include "readFromFile.h"
#include <stdio.h>
#include <stdlib.h>

bool testFile(void)
{
	bool result = true;
	int array[5] = { 6, 2, 123, 6, 3 };
	List* newList = readFromFile("test.txt");
	if (newList == NULL)
	{
		return false;
	}
	if (length(newList) != 5)
	{
		result = false;
		printf("Первый тест на чтение из файла провален\n");
	}
	for (int i = 0; i < 5; i++)
	{
		int value = 0;
		getValue(newList, i, &value);
		if (value != array[i])
		{
			result = false;
			printf("Второй тест на чтение из файла провален\n");
			break;
		}
	}
	deleteList(&newList);
	return result;
}

bool testReverse(void)
{
	bool result = true;
	List* firList = readFromFile("test.txt");
	if (firList == NULL)
	{
		return false;
	}
	List* secList = reverse(firList);
	if (length(secList) != length(firList))
	{
		printf("Первый тест на переворот провален\n");
		result = false;
	}
	for (int i = 0; i < length(firList); i++)
	{
		int firValue = 0;
		int secValue = 0;
		getValue(firList, i, &firValue);
		getValue(secList, length(firList) - 1 - i, &secValue);
		if (firValue != secValue)
		{
			printf("Второй тест на переворот провален\n");
			result = false;
			break;
		}
	}
	deleteList(&firList);
	deleteList(&secList);
	return result;
}

bool testForTask(void)
{
	return !testFile() + !testReverse();
}
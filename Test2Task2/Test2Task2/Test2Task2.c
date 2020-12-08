#include "readFromFile.h"
#include "../../NewList/List/List.h"
#include "transformList.h"
#include "../../NewList/List/listTests.h"
#include <stdio.h>

int main(void)
{	
	List* list = readFromFile("task.txt");
	list = removeDuplicates(list);
	for (int i = 0; i < length(list); i++)
	{
		printf("%s\n", getValue(list, i));
	}
	deleteList(&list);
}
#include "quickSort.h"
#include "readData.h"
#include "../../Test2Task1/Test2Task1/List.h"
#include "transformData.h"
#include "../../Test2Task1/Test2Task1/testForList.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

bool testForTask(void)
{	
	bool result = true;
	List* list = createList();
	append(list, 10);
	append(list, 5);
	append(list, 4);
	append(list, 5);
	append(list, 10);
	int array[5] = { 0 };
	transformToArray(array, list);
	int arrayTest[5] = { 4, 5, 5, 10, 10 };
	quickSort(array, 0, 4);
	for (int i = 0; i < 5; i++)
	{
		if (array[i] != arrayTest[i])
		{
			result = false;
		}
	}
	deleteList(&list);
	return result;
}

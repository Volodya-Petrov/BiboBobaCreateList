#include "../../Test2Task1/Test2Task1/List.h"
#include <stdlib.h>

void transformToArray(int array[], List* list)
{	
	if (list == NULL)
	{
		return NULL;
	}
	for (int i = 0; i < length(list); i++)
	{	
		int number = 0;
		getValue(list, i, &number);
		array[i] = number;
	}
}

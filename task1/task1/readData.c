#include "../../Test2Task1/Test2Task1/List.h"
#include <stdio.h>

List* readData(void)
{	
	List* newList = createList();
	if (newList == NULL)
	{
		return NULL;
	}
	printf("¬ведите числа:\n");
	int number = 0;
	scanf("%i", &number);
	while (number != 0)
	{
		append(newList, number);
		scanf("%i", &number);
	}
	return newList;
}
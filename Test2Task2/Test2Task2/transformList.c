#include "transformList.h"
#include "../../NewList/List/List.h"
#include <stdlib.h>

List* removeDuplicates(List* oldList)
{	
	if (oldList == NULL)
	{
		return NULL;
	}
	List* newList = createList();
	if (newList == NULL)
	{
		return oldList;
	}
	char* value = NULL;
	while (length(oldList) > 0)
	{
		char* value = getValue(oldList, 0);
		if (indexOf(newList, value) == -1)
		{
			append(newList, value);
		}
		deleteElement(oldList, 0);
	}
	deleteList(&oldList);
	return newList;
}
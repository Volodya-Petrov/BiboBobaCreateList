#include "reverseList.h"
#include "List.h"
#include <stdlib.h>

List* reverse(List* oldList)
{
	if (length(oldList) == 0)
	{
		return NULL;
	}
	List* newList = createList();
	if (newList == NULL)
	{
		return NULL;
	}
	for (int i = length(oldList) - 1; i >= 0; i--)
	{	
		int value = 0;
		getValue(oldList, i, &value);
		append(newList, value);
	}
	return newList;
}
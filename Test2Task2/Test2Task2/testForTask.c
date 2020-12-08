#include "../../NewList/List/List.h"
#include "readFromFile.h"
#include "transformList.h"
#include <stdbool.h>

bool testForTask(void)
{
	bool result = true;
	List* list = readFromFile("test.txt");
	list = removeDuplicates(list);
	if (indexOf(list, "f") == -1 || indexOf(list, "abc") == -1 || indexOf(list, "ff") == 1 || length(list) != 3)
	{
		result = false;
	}
	deleteList(&list);
	return result;
}
#include "readFromFile.h"
#include "../../NewList/List/List.h"
#include "transformList.h"
#include "../../NewList/List/listTests.h"

int main(void)
{	
	List* list = readFromFile("task.txt");
	list = removeDuplicates(list);
	deleteList(&list);
}
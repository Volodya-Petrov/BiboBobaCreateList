#include "readFromFile.h"
#include "List.h"
#include <stdio.h>

List* readFromFile(char fileName[])
{	
	List* list = createList();
	if (list == NULL)
	{
		return NULL;
	}
	FILE* fileOpen = fopen(fileName, "r");
	int value = 0;
	while (fscanf(fileOpen, "%i", &value) != EOF)
	{
		append(list, value);
	}
	fclose(fileOpen);
	return list;
}
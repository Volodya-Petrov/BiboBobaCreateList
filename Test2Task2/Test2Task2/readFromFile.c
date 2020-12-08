#include "../../NewList/List/List.h"
#include "readFromFile.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE_OF_STRING 10000

List* readFromFile(char filename[])
{	
	List* list = createList();
	if (list == NULL)
	{
		return NULL;
	}
	FILE* fileOpen = fopen(filename, "r");
	char* string = calloc(SIZE_OF_STRING, sizeof(char));
	while (feof(fileOpen) == 0)
	{	
		string = fgets(string, SIZE_OF_STRING, fileOpen);
		if (string[strlen(string) - 1] == '\n')
		{
			string[strlen(string) - 1] = '\0';
		}
		append(list, string);
	}
	free(string);
	fclose(fileOpen);
	return list;
}
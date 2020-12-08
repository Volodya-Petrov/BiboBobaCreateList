﻿#include "List.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ListElement
{
	char* value;
	struct ListElement* next;
} ListElement;

typedef struct List
{	
	int length;
	ListElement* head;
	ListElement* tail;
} List;

List* createList()
{
	List* newList = malloc(sizeof(List));
	if (newList == NULL)
	{
		return NULL;
	}
	newList->length = 0;
	newList->head = NULL;
	newList->tail = NULL;
	return newList;
}

int length(List* list)
{
	if (list->head == NULL || list->tail == NULL)
	{
		return 0;
	}
	return list->length;
}

char* getValue(List* list, int index)
{
	if (index < 0 || index >= length(list))
	{
		return 0;
	}
	int currentIndex = 0;
	ListElement* currentElement = list->head;
	while (true)
	{
		if (currentIndex == index)
		{
			return currentElement->value;
		}
		currentElement = currentElement->next;
		currentIndex++;
	}
}

int indexOf(List* list, char* value)
{
	if (list->head == NULL)
	{
		return -1;
	}
	int currentIndex = 0;
	ListElement* currentElement = list->head;
	while (currentElement != NULL)
	{
		if (strcmp(currentElement->value, value) == 0)
		{
			return currentIndex;
		}
		currentElement = currentElement->next;
		currentIndex++;
	}
	return -1;
}

bool append(List* list, char* value)
{
	ListElement* newElement = malloc(sizeof(ListElement));
	if (newElement == NULL)
	{
		return false;
	}
	char* newValue = malloc(strlen(value) + 1);
	if (newValue == NULL)
	{
		free(newElement);
		return false;
	}
	strcpy(newValue, value);
	list->length++;
	newElement->next = NULL;
	newElement->value = newValue;
	if (list->head == NULL)
	{
		list->head = newElement;
		list->tail = newElement;
		return true;
	}
	list->tail->next = newElement;
	list->tail = newElement;
	return true;
}

bool deleteElement(struct List* list, int index)
{
	if (index < 0 || index >= length(list))
	{
		return false;
	}
	if (list->head == NULL)
	{
		return false;
	}
	if (index == 0)
	{
		ListElement* oldElement = list->head;
		if (length(list) == 1)
		{
			list->head = NULL;
			list->tail = NULL;
			list->length--;
			free(oldElement->value);
			free(oldElement);
			return true;
		}
		list->head = list->head->next;
		free(oldElement->value);
		free(oldElement);
		list->length--;
		return true;
	}
	int currentIndex = 0;
	ListElement* currentElement = list->head;
	while (true)
	{
		if (index - currentIndex == 1)
		{
			ListElement* oldElement = currentElement->next;
			currentElement->next = currentElement->next->next;
			if (oldElement == list->tail)
			{
				list->tail = currentElement;
			}
			free(oldElement->value);
			free(oldElement);
			return true;
		}
		currentIndex++;
		currentElement = currentElement->next;
	}
}

void deleteList(List** list)
{
	while (length(*list) > 0)
	{
		deleteElement(*list, 0);
	}
	free(*list);
	*list = NULL;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int number;
	ListElement *next;
} ListElement;

typedef struct
{
	ListElement* head;
}List;

ListElement* insert(ListElement* head, int index)
{
	ListElement* currentElement = head;
	for (int i = 0; i < index; ++i)
	{
		currentElement = currentElement->next;
	}
	ListElement* newItem = malloc(sizeof(ListElement));
	newItem = 
	
}

List* createList(int numberOfElements)
{	
	ListElement* head = malloc(sizeof(ListElement));
	tail->number = 0;
	tail->next = NULL;
	List* newList = malloc(sizeof(List));
	newList->head = &head;
 	for (int i = 0; i < numberOfElements - 1; i++)
	{
		newList->header = append();
	}
}



int main(void)
{
	ListElement* head = NULL;

}
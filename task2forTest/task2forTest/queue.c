#include "queue.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct Element
{
	int value;
	int priority;
	struct Element* next;
} Element;

typedef struct Queue
{
	Element* head;
} Queue;

Queue* createQueue(void)
{
	return calloc(1, sizeof(Queue));
}

Element* createElement(int value, int priority)
{
	Element* element = calloc(1, sizeof(Element));
	if (element == NULL)
	{
		return NULL;
	}
	element->value = value;
	element->priority = priority;
	return element;
}

void enqueue(Queue* queue ,int value, int priority)
{	
	if (queue == NULL)
	{
		return;
	}
	Element* newElement = createElement(value, priority);
	if (newElement == NULL)
	{
		return;
	}
	if (queue->head == NULL)
	{
		queue->head = newElement;
		return;
	}
	if (queue->head->priority < priority)
	{
		newElement->next = queue->head;
		queue->head = newElement;
		return;
	}
	Element* currentElement = queue->head;
	while (true)
	{
		if (currentElement->next == NULL)
		{
			currentElement->next = newElement;
			return;
		}
		if (currentElement->next->priority < priority)
		{
			newElement->next = currentElement->next;
			currentElement->next = newElement;
			return;
		}
		currentElement = currentElement->next;
	}
}

int dequeue(Queue* queue)
{	
	if (queue == NULL)
	{
		return -1;
	}
	Element* oldElement = queue->head;
	if (oldElement == NULL)
	{
		return -1;
	}
	queue->head = queue->head->next;
	int value = oldElement->value;
	free(oldElement);
	return value;
}

void deleteQueue(Queue** queue)
{	
	if (*queue == NULL)
	{
		return;
	}
	while ((*queue)->head != NULL)
	{
		int value = dequeue(*queue);
	}
	free(*queue);
	*queue = NULL;
}
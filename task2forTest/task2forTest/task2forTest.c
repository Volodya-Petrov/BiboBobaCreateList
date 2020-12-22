#include "testForQueue.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{	
	setlocale(LC_ALL, "rus");
	if (!queueTests())
	{
		printf("Тесты провалены\n");
		return 1;
	}
	printf("Тесты пройдены успешно\n");
	Queue* queue = createQueue();
	int value = 1;
	int priority = 1;
	printf("Введите значение: ");
	scanf("%i", &value);
	printf("Введите приоритет: ");
	scanf("%i", &priority);
	while (value != 0)
	{
		enqueue(queue, value, priority);
		printf("Введите значение: ");
		scanf("%i", &value);
		printf("Введите приоритет: ");
		scanf("%i", &priority);
	}
	value = dequeue(queue);
	while (value != -1)
	{
		printf("%i ", value);
		value = dequeue(queue);
	}
	deleteQueue(&queue);
}

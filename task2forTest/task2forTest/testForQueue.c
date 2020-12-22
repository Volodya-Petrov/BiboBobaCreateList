#include "queue.h"
#include "testForQueue.h"
#include <stdbool.h>
#include <stdlib.h>

bool queueTests(void)
{	
	bool result = true;
	Queue* queue = createQueue();
	enqueue(queue, 2, 12);
	enqueue(queue, 5, 5);
	enqueue(queue, 13, 12);
	enqueue(queue, 5, 18);
	enqueue(queue, 7, 15);
	if (dequeue(queue) != 5)
	{
		result = false;
	}
	if (dequeue(queue) != 7)
	{
		result = false;
	}
	if (dequeue(queue) != 2)
	{
		result = false;
	}
	if (dequeue(queue) != 13)
	{
		result = false;
	}
	if (dequeue(queue) != 5)
	{
		result = false;
	}
	if (dequeue(queue) != -1)
	{
		result = false;
	}
	deleteQueue(&queue);
	return result;
}
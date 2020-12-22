#pragma once

// стуктура очереди с приоритетом
typedef struct Queue Queue;

// создание очереди
Queue* createQueue(void);

// добавление элемента в очередь
void enqueue(Queue* queue, int value, int priority);

// получения значения элемента с наибольшим приоритетом и удаление его из очереди
int dequeue(Queue* queue);

// удаление очереди
void deleteQueue(Queue** queue);
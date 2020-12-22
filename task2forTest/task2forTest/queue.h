#pragma once

// �������� ������� � �����������
typedef struct Queue Queue;

// �������� �������
Queue* createQueue(void);

// ���������� �������� � �������
void enqueue(Queue* queue, int value, int priority);

// ��������� �������� �������� � ���������� ����������� � �������� ��� �� �������
int dequeue(Queue* queue);

// �������� �������
void deleteQueue(Queue** queue);
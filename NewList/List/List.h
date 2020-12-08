#pragma once

#include <stdbool.h>

// структура списка
typedef struct List List;

// создание списка
List* createList();

// выдает длину списка
int length(List* list);

// выдает значение по индексу
char* getValue(List* list, int index);

// выдает индекс по значению
int indexOf(List* list, char* value);

// добавление элемента в конец списка
bool append(List* list, char* value);

// удаление элемента по индексу
bool deleteElement(struct List* list, int index);

// удаление списка
void deleteList(List** list);
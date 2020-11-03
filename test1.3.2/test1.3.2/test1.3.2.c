#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define RFACTOR (1.24733)

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}

void combSort(int array[], int size)
{   
    if (size <= 0)
    {
        return;
    }
    int gap = size;
    int swaps = 1;
    int j = 0;
    while (gap > 1 || swaps)
    {
        gap = (int)(gap / RFACTOR);
        if (gap < 1)
        {
            gap = 1;
        }
        swaps = 0;
        for (int i = 0; i < size - gap; ++i)
        {
            j = i + gap;
            if (array[i] > array[j])
            {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                swaps = 1;
            }
        }
    }
}

int main(void)
{   
    setlocale(LC_ALL, "rus");
    int size = 0;
    printf("Введите размер массива: ");
    while (scanf("%i", &size) == 0)
    {
        scanf("%*s");
        printf("Некорректный ввод, повтори попытку\n");
        printf("Введите размер массива: ");
    }
    int* array = malloc(sizeof(int) * size);
    if (array == NULL)
    {
        printf("Не дали память :(\n");
        return 1;
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = 200 * rand() / RAND_MAX - 100;
    }
    printArray(array, size);
    combSort(array, size);
    printf("Отсортированный массив:\n");
    printArray(array, size);
    free(array);
}
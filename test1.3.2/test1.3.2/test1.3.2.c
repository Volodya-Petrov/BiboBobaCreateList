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
    scanf("%i", &size);
    int* array = malloc(sizeof(int) * size);
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
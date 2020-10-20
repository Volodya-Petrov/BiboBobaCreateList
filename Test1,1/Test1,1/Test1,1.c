#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE_OF_ARRAY 10

int sumOfDigits(int number)
{	
	int sum = 0;
	number = abs(number);
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}
	return sum;
}

int main(void)
{	
	int max = 0;
	int arrayOfNums[SIZE_OF_ARRAY] = { 0 };
	int arrayOfDigitsSum[SIZE_OF_ARRAY] = { 0 };
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		arrayOfNums[i] = 2000 * rand() / RAND_MAX - 1000;
		arrayOfDigitsSum[i] = sumOfDigits(arrayOfNums[i]);
		if (max < arrayOfDigitsSum[i])
		{
			max = arrayOfDigitsSum[i];
		}
	}
	for (int i = 0; i < SIZE_OF_ARRAY; i++)
	{
		if (arrayOfDigitsSum[i] == max)
		{
			printf("%i ", arrayOfNums[i]);
		}
	}
}

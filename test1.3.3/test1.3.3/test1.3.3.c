#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	FILE* fileOpen = fopen("test.txt", "r");
	char currentChar = '\0';
	char oldChar = '\0';
	bool firstRead = true;
	while ((currentChar = fgetc(fileOpen)) != EOF)
	{	
		if (!firstRead)
		{
			if (currentChar != oldChar)
			{
				printf("%c", oldChar);
			}
		}
		firstRead = false;
		oldChar = currentChar;
	}
	printf("%c", oldChar);
	fclose(fileOpen);
}
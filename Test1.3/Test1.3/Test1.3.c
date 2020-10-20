#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main(void)
{	
	setlocale(LC_ALL, "");
	FILE* fileOpen = fopen("test.txt", "r");
	char charInReal = '\0';
	bool beginOfString = true;
	bool needPrint = false;
	while ((charInReal = fgetc(fileOpen)) != EOF)
	{
		if (beginOfString)
		{
			if (charInReal == ';')
			{
				needPrint = true;
				beginOfString = false;
			}
		}
		if (needPrint)
		{
			printf("%c", charInReal);
		}
		if (charInReal == '\n')
		{
			beginOfString = true;
			needPrint = false;
		}
	}
	fclose(fileOpen);
}
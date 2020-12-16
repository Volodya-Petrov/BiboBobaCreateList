#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Node.h"
#include <locale.h>

typedef struct
{
	int length;
	Node** nodes;
} Forest;

Forest* createForest(char* string)
{
	// Count symbols
	int table[256] = { 0 };
	int stringLength = strlen(string);
	for (int i = 0; i < stringLength; i++)
	{	
		if (('a' <= string[i] && string[i] <= 'z') || ('а' <= string[i] && string[i] <= 'я'))
		{
			unsigned char charCode = (unsigned char)string[i];
			table[charCode]++;
		}
	}

	// Create forest
	int valuableCount = 0;
	for (int i = 0; i < 256; i++)
	{
		if (table[i] != 0)
		{
			valuableCount++;
		}
	}
	Forest* forest = calloc(1, sizeof(Forest));
	if (forest == NULL)
	{
		return NULL;
	}
	forest->length = valuableCount;
	forest->nodes = malloc(sizeof(Node*) * valuableCount);
	if (forest->nodes == NULL)
	{
		free(forest);
		return NULL;
	}

	// Fill the forest
	int forestIndex = 0;
	for (int i = 0; i < 256; i++)
	{
		if (table[i] != 0)
		{
			forest->nodes[forestIndex] = createNode(table[i], i, NULL, NULL);
			forestIndex++;
		}
	}
	return forest;
}

Node* treeCreate(Forest* forest)
{	
	while (forest->length > 1)
	{
		int min = 0;
		for (int i = 1; i < forest->length; i++)
		{		
			if (forest->nodes[i]->freq < forest->nodes[min]->freq)
			{	
				min = i;
			}
		}
		int secondMin = -1;
		for (int i = 0; i < forest->length; i++)
		{
			if (i != min)
			{
				if (secondMin == -1)
				{
					secondMin = i;
				}
				else
				{
					if (forest->nodes[i]->freq < forest->nodes[secondMin]->freq)
					{
						secondMin = i;
					}
				}
			}
		}
		int freq = forest->nodes[min]->freq + forest->nodes[secondMin]->freq;
		Node* newRoot = createNode(freq, '\0', forest->nodes[min], forest->nodes[secondMin]);
		forest->nodes[min] = newRoot;
		for (int i = secondMin; i < forest->length - 1; i++)
		{
			forest->nodes[i] = forest->nodes[i + 1];
		}
		forest->length--;
	}
	return forest->nodes[0];
}

void preorder(Node* root, char* path, int length)
{
	if (root->symbol != '\0')
	{	
		printf("%c - %s\n", root->symbol, path);
		return; 
	}
	path[length] = '0';
	path[length + 1] = '\0';
	preorder(root->left, path, length + 1);
	path[length] = '1';
	path[length + 1] = '\0';
	preorder(root->right, path, length + 1);
}

int main()
{
	setlocale(LC_ALL, "rus");
	char string[] = "володя докажите, что энтропия монетки принимает наибольшее значение для правильной монетки петров";
	Forest* forest = createForest(string);
	for (int i = 0; i < forest->length; i++)
	{
		Node* node = forest->nodes[i];
		printf("%c - %d; ", node->symbol, node->freq);
	}
	Node* root = treeCreate(forest);
	char path[256] = { 0 };
	printf("\n");
	preorder(root, path, 0);
	free(forest->nodes);
	free(forest);
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Node.h"

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
		string[i] = tolower(string[i]);
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
	for (int i = 0; i < valuableCount; i++)
	{
		if (forest->nodes[i] == NULL)
		{	
			for (int j = 0; j < i; j++)
			{
				free(forest->nodes[j]);
			}
			free(forest);
			return NULL;
		}
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

void preorder(Node* root, char* path, int length, char* table[256])
{
	if (root->symbol != '\0')
	{	
		char* copy = calloc(length + 1, sizeof(char));
		strcpy(copy, path);
		table[(unsigned)root->symbol] = copy;
		return; 
	}
	path[length] = '0';
	path[length + 1] = '\0';
	preorder(root->left, path, length + 1, table);
	path[length] = '1';
	path[length + 1] = '\0';
	preorder(root->right, path, length + 1, table);
}

int main()
{
	char* string = "Володя Докажите, что энтропия монетки принимает наибольшее значение для правильной монетки Петров";
	Forest* forest = createForest(string);
	for (int i = 0; i < forest->length; i++)
	{
		Node* node = forest->nodes[i];
		printf("%c - %d; ", node->symbol, node->freq);
	}
	Node* root = treeCreate(forest);
	char* table[256] = { 0 };
	char path[256] = { 0 };
	preorder(root, path, 0, table);
	printf("\n");
	for (int i = 0; i < 256; i++)
	{
		if (table[i] != NULL)
		{
			printf("%c - %s\n", i, table[i]);
		}
	}
	free(forest->nodes);
	free(forest);
}
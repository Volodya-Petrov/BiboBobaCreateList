#include "Node.h"
#include <stdlib.h>

Node* createNode(int freq, char symbol, Node* left, Node* right)
{
	Node* newNode = malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->freq = freq;
	newNode->symbol = symbol;
	newNode->left = left;
	newNode->right = right;
	return newNode;
}
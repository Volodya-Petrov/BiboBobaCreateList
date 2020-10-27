#pragma once
typedef struct
{
	int freq;
	char symbol;
	struct Node* left;
	struct Node* right;
} Node;

// Create new node
Node* createNode(int freq, char symbol, Node* left, Node* right);

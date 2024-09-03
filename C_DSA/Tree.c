#include <stdlib.h>
#include <stdio.h>
#include "Tree.h"

BinarySearchTree* createBinaryTree(int data)
{
	BinarySearchTree* tree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
	if (tree == NULL)
	{
		fprintf(stderr, "Memoryallocation failed");
		exit(1);
	}

	TreeNode* rootNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (rootNode == NULL)
	{
		fprintf(stderr, "Memory allocation failed");
		exit(1);
	}
	rootNode->rightNode = NULL;
	rootNode->leftNode = NULL;
	tree->root = rootNode;

	return tree;
}

void insertNode(BinarySearchTree* tree, int data)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	if (node == NULL)
	{
		fprintf(stderr, "Memory allocation failed");
		exit(1);
	}
	node->data = data;
	node->rightNode = NULL;
	node->leftNode = NULL;

	// Insert as root if tree is empty
	if (tree->root == NULL)
	{
		tree->root = node;
	}
	else
	{
		TreeNode* currentNode = tree->root;
		while (currentNode != NULL)
		{
			if (node->data < currentNode->data)
			{
				if (currentNode->leftNode == NULL)
				{
					currentNode->leftNode = node;
					break;
				}
				else
				{
					currentNode = currentNode->leftNode;
				}
			}
			else
			{
				if (currentNode->rightNode == NULL)
				{
					currentNode->rightNode = node;
					break;
				}
				else
				{
					currentNode = currentNode->rightNode;
				}
			}
		}
	}
}

int search(BinarySearchTree* tree, TreeNode* currentNode, int target)
{
	if (tree->root == NULL)
	{
		fprintf(stderr, "Empty tree");
		exit(1);
	}

	return currentNode = target;
}

int findSmallest(BinarySearchTree* tree)
{
	TreeNode* currentNode = tree->root;
	if (currentNode == NULL)
	{
		fprintf(stderr, "Tree is empty");
		exit(1);
	}

	while (currentNode->leftNode != NULL)
	{
		currentNode = currentNode->leftNode;
	}

	return currentNode->data;
}

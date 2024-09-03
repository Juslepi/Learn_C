#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Linked_list.h"

LinkedList* createLinkedList(int head)
{
	LinkedList* linkedList = (LinkedList*)malloc(sizeof(LinkedList));
	if (linkedList == NULL) {
		fprintf(stderr, "Memory allocation for linked list failed\n");
		exit(1);
	}

	Node* headNode = (Node*)malloc(sizeof(Node));
	if (headNode == NULL) {
		fprintf(stderr, "Memory allocation for node failed");
		exit(1);
	}
	headNode->data = head;
	headNode->next = NULL;
	linkedList->head = headNode;

	return linkedList;
}

void insert(LinkedList* linkedList, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) {
		fprintf(stderr, "Memory allocation for node failed");
		exit(1);
	}
	node->data = data;
	node->next = NULL;

	// Insert node
	if (linkedList->head == NULL)
	{
		linkedList->head = node;
	}
	else {
		Node* current = linkedList->head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = node;
	}
}

void insertAtPosition(LinkedList* linkedList, int target, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL) {
		fprintf(stderr, "Memory allocation for node failed");
		exit(1);
	}
	node->data = data;
	node->next = NULL;

	int currentPosition = 0;
	Node* currentNode = linkedList->head;

	if (target == 0)
	{
		node->next = currentNode;
		linkedList->head = node;
	}

	while (currentPosition <= target)
	{
		Node* tmp = currentNode->next;

		if (tmp->next != NULL && currentPosition < target)
		{
			fprintf(stderr, "Missing link in linked list");
			exit(1);
		}
		if (currentPosition == target)
		{
			currentNode->next = node;
			node->next = tmp;
		}
		currentPosition++;
	}
}

int deleteFirst(LinkedList* linkedList)
{
	if (isEmpty(linkedList))
	{
		fprintf(stderr, "Linked list empty");
		exit(1);
	}
	Node* nodeToDelete = linkedList->head;
	int removedValue = nodeToDelete->data;
	linkedList->head = linkedList->head->next;
	free(nodeToDelete);

	return removedValue;
}

int deleteLast(LinkedList* linkedList)
{
	if (isEmpty(linkedList))
	{
		fprintf(stderr, "Linked list is empty;");
		exit(1);
	}

	Node* currentNode = linkedList->head;
	Node* previousNode = NULL;
	while (currentNode->next != NULL)
	{
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	int removedData = currentNode->data;

	if (previousNode != NULL)
	{
		previousNode->next = NULL;
	}
	else
	{
		linkedList->head = NULL;
	}

	free(currentNode);

	return removedData;
}

int deleteTargetNode(LinkedList* linkedList, int target)
{
	if (isEmpty(linkedList))
	{
		fprintf(stderr, "Empty linked list\n");
		return -1;
	}

	Node* currentNode = linkedList->head;
	Node* previousNode = NULL;
	int index = 0;

	if (currentNode->data == target)
	{
		linkedList->head = currentNode->next;
		free(currentNode);
		return index;
	}

	while (currentNode->next != NULL)
	{
		index++;
		previousNode = currentNode;
		currentNode = currentNode->next;

		if (currentNode->data == target)
		{
			previousNode->next = currentNode->next;
			free(currentNode);
			return index;
		}
	}

	fprintf(stderr, "Target not found in the linked list\n");
	return -1;
}

int deleteAllTargetNodes(LinkedList* linkedList, int target)
{
	int removeCount = 0;
	Node* currentNode = linkedList->head;
	Node* previousNode = NULL;

	while (currentNode != NULL)
	{
		if (currentNode->data == target)
		{
			Node* nodeToRemove = currentNode;

			if (previousNode == NULL)
			{
				// If the first node contains the target, update the head.
				linkedList->head = currentNode->next;
				currentNode = linkedList->head;
			}
			else
			{
				previousNode->next = currentNode->next;
				currentNode = currentNode->next;
			}

			free(nodeToRemove);
			removeCount++;
		}
		else
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
		}
	}

	return removeCount;
}

void printLinkedList(LinkedList* linkedList)
{
	if (isEmpty(linkedList))
	{
		fprintf(stderr, "Empty linked list\n");
		return;
	}

	int counter = 1;
	Node* currentNode = linkedList->head;
	while (currentNode != NULL)
	{
		printf("%i. Element: %i\n", counter, currentNode->data);
		currentNode = currentNode->next;
		counter++;
	}
}

bool isEmpty(LinkedList* linkedList)
{
	return linkedList->head == NULL;
}

int getSize(LinkedList* linkedList)
{
	int size = 0;
	Node* currentNode = linkedList->head;

	while (currentNode != NULL)
	{
		size++;
		currentNode = currentNode->next;
	}

	return size;
}

void reverseLinkedList(LinkedList* linkedList)
{
	fprintf(stderr, "Not implemented");
	exit(1);
}


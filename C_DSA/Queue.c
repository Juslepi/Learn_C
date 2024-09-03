#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int data;
	struct Node* next;
} Node;

typedef struct {
	Node* first;
} Queue;

Queue* create_queue(int data);
void insert(Queue* queue, int data);
int delete_element(Queue* queue);
int peek(Queue* queue);
void display(Queue* queue);

Queue* create_queue(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL)
	{
		fprintf(stderr, "Memory allocation failed");
		exit(1);
	}
	node->data = data;
	node->next = NULL;

	Queue* queue = (Queue*)malloc(sizeof(Queue));
	if (queue == NULL)
	{
		fprintf(stderr, "Memory allocation failed");
		exit(1);
	}
	queue->first = node;

	return queue;
}

void insert(Queue* queue, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL)
	{
		fprintf(stderr, "Memory allocation failed");
		exit(1);
	}
	node->data = data;
	node->next = NULL;

	if (queue->first == NULL)
	{
		queue->first = node;
	}
	else
	{
		Node* current = queue->first;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = node;
	}
}

int delete_element(Queue* queue)
{
	if (queue == NULL || queue->first == NULL) 
	{
		fprintf(stderr, "Queue is empty");
		exit(1);
	}

	Node* removed = queue->first;
	int removedData = removed->data;
	queue->first = queue->first->next;
	free(removed);

	return removedData;
}

int peek(Queue* queue)
{
	if (queue->first == NULL)
	{
		fprintf(stderr, "Queue is empty");
		exit(1);
	}
	return queue->first->data;
}

void display(Queue* queue)
{
	if (queue->first == NULL)
	{
		fprintf(stderr, "Queue is empty");
		exit(1);
	}

	Node* current = queue->first;
	int counter = 1;
	while (current->next != NULL)
	{
		printf("%i. Element: %i\n", counter, current->data);
		current = current->next;
		counter++;
	}
}

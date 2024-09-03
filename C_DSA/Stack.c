#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

#define MAX_SIZE 100

Stack* createStack()
{
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack == NULL)
	{
		printf("Memory allocation failed");
		exit(1);
	}
	stack->top = NULL;
	return stack;
}

int stackIsEmpty(Stack* stack)
{
	return stack->top == NULL;
}

void push(Stack* stack, int val)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL)
	{
		printf("Memory allocation for node failed");
		exit(1);
	}
	node->data = val;
	node->next = stack->top;
	stack->top = node;
}

int peek(Stack* stack)
{
	if (stackIsEmpty(stack))
	{
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	return stack->top->data;
}

int pop(Stack* stack)
{
	if (stackIsEmpty(stack))
	{
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}

	Node* removed = stack->top;
	int data = removed->data;
	stack->top = stack->top->next;
	free(removed);

	return data;
}

void display(Stack* stack)
{
	Node* current = stack->top;
	while (current != NULL);
	{
		printf("Stack item: %d\n", current->data);
		current = current->next;
	}
}

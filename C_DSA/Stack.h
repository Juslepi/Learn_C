#pragma once

typedef struct Node
{
	int data;
	struct Node* next;
} Node;

typedef struct
{
	Node* top;
} Stack;

// Definitions
Stack* createStack();
int stackIsEmpty(Stack* stack);
void push(Stack* stack, int val);
int pop();
int peek(Stack* stack);
void display(Stack* stack);

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct {
	int data;
	struct Node* next;
} Node;

typedef struct {
	Node* head;
} LinkedList;

// Header'
LinkedList* createLinkedList(int head);
void insert(LinkedList* linkedList, int data);
void insertAtPosition(LinkedList* linkedList, int data);
int deleteFirst(LinkedList* linkedList);
int deleteLast(LinkedList* linkedList);
int deleteTargetNode(LinkedList* linkedList, int target);
int deleteAllTargetNodes(LinkedList* linkedList, int target);
void printList(LinkedList* linkedList);
int searchNode(LinkedList* linkedList);
bool isEmpty(LinkedList* linkedList);
int getSize(LinkedList* linkedList);
void reverseLinkedList(LinkedList* linkedList);
void sortLinkedList(LinkedList* linkedList);
#endif // !LINKED_LIST_H
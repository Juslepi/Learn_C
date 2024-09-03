#ifndef TREE_H
#define TREE_H

typedef struct {
	int data;
	struct TreeNode* rightNode;
	struct TreeNode* leftNode;
} TreeNode;

typedef struct {
	TreeNode* root;
} BinarySearchTree;

BinarySearchTree* createBinaryTree(int data);
void insertNode(BinarySearchTree* tree, int data);
void insert(BinarySearchTree*, int data);
int findSmallest(BinarySearchTree* tree, int data);
int search(BinarySearchTree* bst, int target);

#endif // !TREE_H
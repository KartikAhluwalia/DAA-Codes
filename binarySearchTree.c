#include<stdio.h>
#include<stdlib.h>

struct node{
	int item;
	struct node* left;
	struct node* right;
};

struct node* createNode(int value){
	struct node* newNode = malloc(sizeof(struct node));
	newNode->item = value;
	newNode->left = NULL;
	newNode->right = NULL;
}

struct node* insert(struct node* root, int value){
	if(root==NULL){
		return createNode(value);
	}
	if(value<root->item){
		root->left = insert(root->left,value);
	}
	else{
		root->right = insert(root->right,value);
	}
	return root;
}

void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d -> ", root->item);
    inorder(root->right);
  }
}

int main()
{
	struct node* root = createNode(2);
	root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);
    inorder(root);

	return 0;
}
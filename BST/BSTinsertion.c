#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node * left;
	struct node * right;
	int data;
};


void insert(struct node * bst,int key){
	struct node * ptr, * reserve;
	while(bst!=NULL){
		reserve = bst;

		if(key == bst->data){
			return;
		}
		else if(key < bst->data){
			bst = bst->left;
		}
		else
			bst = bst->right;
	}

	ptr = (struct node *)malloc(sizeof(struct node));

	ptr->data = key;
	ptr->left = ptr->right = NULL;

	if(key < reserve->data){
		reserve->left = ptr;
	}
	else
		reserve->right = ptr;
}


void inorder(struct node * tree){
	if(tree!=NULL){
		inorder(tree->left);
		printf("\n%d",tree->data);
		inorder(tree->right);
	}
}


int main(){
	struct node * root;
	root =  (struct node *)malloc(sizeof(struct node));
	root->data = 45;
	insert(root,39);
	insert(root,56);
	insert(root,12);
	insert(root,34);
  	insert(root,78);
  	insert(root,32);
  	insert(root,10);
  	insert(root,89);
  	insert(root,54);
  	insert(root,67);
  	insert(root,81);
  	insert(root,90);


	inorder(root);
}
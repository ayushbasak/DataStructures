#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node * left;
	struct node * right;
	int data;
};

int Height(struct node * tree){
  int x,y;
  if(tree == NULL)
    return 0;
    x = Height(tree->left);
    y = Height(tree->right);

  return x>y?x+1:y+1;
}

struct node * pred(struct node * ptr){
  while(ptr && ptr->right!=NULL)
    ptr = ptr->right;

  return ptr;
}

struct node * succ(struct node * ptr){
  while(ptr && ptr->left!=NULL)
    ptr = ptr->left;

  return ptr;
}


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
		printf("%d ",tree->data);
		inorder(tree->right);
	}
}


struct node * delete(struct node * tree,int key){
  struct node * q;
  if(tree == NULL)
    return tree;
  if(tree->left && tree->right == NULL)
    free(tree);
  

  if(key < tree->data){
    tree->left = delete(tree->left,key);
  }
  else if(key > tree->data){
    tree->right = delete(tree->right,key);
  }
  else{
    if(Height(tree->left)>Height(tree->right)){
      q = pred(tree->left);
      tree->data = q->data;
      tree->left = delete(tree->left,q->data);
    }
    else{
      q = pred(tree->right);
      tree->data = q->data;
      tree->right = delete(tree->right,q->data);
    }
  }

  return tree;
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

  delete(root,39);

  printf("\n\n");
}
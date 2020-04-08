#include "tree.h"
void inorder(struct tree * ptr){
	if(ptr==NULL)
		return;
	inorder(ptr->left);
	printf("%c , ",ptr->data);
	inorder(ptr->right);
}

void preorder(struct tree * ptr){
	if(ptr==NULL)
		return;
	printf("%c , ",ptr->data);
	inorder(ptr->left);
	inorder(ptr->right);
}

void postorder(struct tree * ptr){
	if(ptr==NULL)
		return;
	inorder(ptr->left);
	inorder(ptr->right);
	printf("%c , ",ptr->data);
}

struct tree * create()
{
	struct tree  * p;
	char x;
	printf("Enter data(-1 for no data):");
	scanf("%c",&x);
	
	if(x==-1)
		return NULL;
	
	p=(struct tree *)malloc(sizeof(struct tree));
	p->data=x;
	
	printf("Enter left child of %c:\n",x);
	p->left=create();
 
	printf("Enter right child of %c:\n",x);
	p->right=create();
	
	return p;
}
int main(){
	struct tree * myTree = create();
	printf("INORDER\n");
	inorder(myTree);
	printf("PREORDER\n");
	preorder(myTree);
	printf("POSTORDER\n");
	postorder(myTree);
}
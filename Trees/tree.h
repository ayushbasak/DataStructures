#include <stdlib.h>
#include <stdio.h>
struct tree{
	char data;
	struct tree * left;
	struct tree * right;
};


void inorder(struct tree * ptr);

void preorder(struct tree * ptr);

void postorder(struct tree * ptr);

struct tree * create();
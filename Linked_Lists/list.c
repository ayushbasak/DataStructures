#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node * head;
struct node * curr;

/*
Note:   We may not use 'curr' pointer and replace it with a loop to search for the last element 
        during insertion, but it is an inefficient process as insertion at last then becomes
        an order of O(n). Here, it is O(1).
*/

void insertNode(int d){
    struct node * newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = d;
    if(curr == NULL){
        head = newNode;
        curr = newNode;
    }
    else{
        curr->next = newNode;
        curr = newNode;
    }
}

void deleteNode(int d){
    struct node * p1,* p2;
    p1 = p2 = head;

    if(head==NULL){
        printf("\nList is Empty!\n");
    } 
    else if(head->next==NULL){
        if(p1->data == d){
            head = NULL;
            free(p1);
        }
        else
        {
            printf("\nNo Such Element\n");
        }
    }
    else if(head->data == d){
        head = head->next;
    }
    else{
        while(p1!=NULL){
            if(p1->data == d)
                break;
            p2 = p1;
            p1= p1->next;
        }
        if(p1==NULL)
            printf("\nNo Such Element!\n");
        else
        {
            p2->next = p1->next;
            free(p1);
        }
        
    }
}


void displayList(){
    struct node * ptr = head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){

    for (int i = 0; i < 100; i++)
    {
        insertNode(i*3);
    }
    printf("Original Node\n");
    displayList();

    for(int i = 0;i < 100; i +=3){
        deleteNode(i*3);
    }
    printf("Deleted some elements\n");
    displayList();
    

}

/*
This process is not totally effecient and is difficult to read.
Writing bad code can help one
realize how to optimise it for a better efficiency.

Task :  Write a better deleteNode function with lesser if else blocks

*/
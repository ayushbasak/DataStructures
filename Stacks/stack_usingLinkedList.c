#include <stdio.h>
#include <stdlib.h>
#define error -303183
struct node{
    int data;
    struct node * next;
};

struct node * head;
struct node * top;

/*
Stacks using linked list is not as efficient as arrays as deallocating memory or POP
takes O(N) instead of O(1)
*/

void push(int d){
    struct node * newNode = malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->data = d;

    if(head == NULL){
        head = newNode;
        top = newNode;
    }
    else{
        top->next = newNode;
        top = newNode;
    }
}
void pop(){
    int d;
    if(head == NULL){
        d = error;
    }
    else
    {
        struct node * ptr,*pre;
        ptr = head;
        while (ptr->next!=NULL)
        {
            pre = ptr;
            ptr = ptr->next;
        }
        pre->next = NULL;
        d = ptr->data;
        free(ptr);
    }
    if(d==error)
        printf("Stakc underflow\n");
    else
    {
        printf("%d was popped \n",d);
    }
    
    
}
void display(){
    struct node * ptr = head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
}

}
int main(){

    for(int i = 0;i<100;i++){
        push(i*5);
    }
    display();

    for(int i = 0;i< 100;i+=10){
        pop();
    }

    display();

}

// Task : The program has certain edge case errors, example during stack underflow. You are supposed to fix that.
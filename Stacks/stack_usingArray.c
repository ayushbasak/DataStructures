#include <stdio.h>
#define size 100

//Declaring Array as Global Variable may solve a lot of un necessary problems

int arr[size];
int top = -1;

//top = 0 can also be used, if Array index is considered to start from 1 

void push(int d){
    if(top!=size-1){
        top++;
        arr[top] = d;
    }
    else
    {
        printf("\nStack Overflow\n");
    }
}
int pop(){
    if(top>=0){
        int d =  arr[top];
        top-=1;
        return d;
    }
    else
    {
        printf("Stack Underflow\n");
    }
}
void display(){

    for(int i = 0;i<=top;i++){
        printf("%d ",arr[i]);
    }

}
int main(){
    push(2);
    push(4);
    push(8);
    push(16);
    push(32);
    push(64);
    push(128);


    display();

    printf("%d was poopped \n",pop());
    printf("%d was poopped \n",pop());
    printf("%d was poopped \n",pop());

    display();

    printf("\nPushed 89 and 85\n");
    push(89);
    push(85);

    display();
}
#include <stdio.h>
#define size 10
int main(){


    /*
    int arr[10] = {1,9,8,3,5,2,7,6,4,0};

    for(int i = 0;i<10;i++)
        printf("%d ",arr[i]); 

    Static Length Arrays
    */


   /*
   int n;
   scanf("%d",&n);

   int arr[n];
   for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(int i = 0;i<n;i++)
        printf("%d ",arr[i]);

    Variable Length Arrays

    */


    //For the next given cases we will operate in static array

    int arr[size] = {1,2,3,4,5,6,7,8};
    
    printf("\nOriginal array:\n");
    for(int i = 0;i<size;i++)
        printf("%d ",arr[i]);

    printf("\n");

    //insert(10) to pos 3;
    int pos = 3;
    for(int k=size-2;k>=pos;k--)
        arr[k] = arr[k-1];
    
    arr[pos] = 10;

    printf("\nInserted Element 10 at pos '3' in  array:\n");
    for(int i = 0;i<size;i++)
        printf("%d ",arr[i]);

    
    printf("\n");
    //delete(10)
    //find element 10 then proceed

    for(int l = 0;l<size;l++){
        if(arr[l]==10){
            for(int k = l;k<size-1;k++)
                arr[k]=arr[k+1];
            break;
        }
    }

    printf("\nDeleted Element 10 in array:\n");
    for(int i = 0;i<size;i++)
        printf("%d ",arr[i]);

    printf("\n");
}
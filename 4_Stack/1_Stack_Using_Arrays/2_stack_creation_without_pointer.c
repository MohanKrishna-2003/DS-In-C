#include<stdio.h>
#include<stdlib.h>

// FUCNTION TO CHECK WHETHER THE STACK IS EMPTY OR NOT
int isEmpty(int a[], int top)
{
    if(top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

// FUCNTION TO CHECK WHETHER THE STACK IS FULL OR NOT
int isFull(int a[], int size, int top)
{
    if(top==size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    int a[10];
    int top = -1;
    int size = 10;

    a[2] = 23;
    top++;
    if(isEmpty(a, top))
    {
        printf("The Stack is Empty\n");
    }
    else{
        printf("The Stack is not Empty\n");
    }

}
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int top;
    int size;
    int *arr;
};

// CHECKING WHETHER THE STACK IS EMPTY OR NOT
int isEmpty(struct stack* ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// CEHCKING WHETHER THE STACK IS FULL OR NOT
int isFull(struct stack* ptr)
{
    if(ptr->size==ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // BY WITHOUT USING POINTER WE ARE ACCESSING THE ATTRIBUTES

    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int*)malloc(s.size*sizeof(int));

    // BY USING POINTER WE ARE ACCESSING THE ATTRIBUTES
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int*)malloc(s->size *sizeof(int));

    // PUSHING AN ELEMENT MANUALLY
    s->arr[0] = 23;
    s->top++;

    if(isEmpty(s))
    {
        printf("The stack is Empty\n");
    }
    else
    {
        printf("The stack is not Empty\n");
    }


    return 0;
    
}
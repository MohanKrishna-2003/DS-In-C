#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack* sp)
{
    if(sp->top == -1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack * sp)
{
    if(sp->top == sp->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack* sp, int val)
{
    if(isFull(sp))
    {
        printf("The Stack is in OverFlow\n");
    }
    else{
        sp->top++;
        sp->arr[sp->top] = val;
    }
}
int pop(struct stack* sp)
{
    int val;
    if(isEmpty(sp))
    {
        printf("The Stack is in UnderFlow\n");
    }
    else{
        val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}
int peek(struct stack* sp, int i)
{
    int arrayInd = sp->top-i+1;
    if(arrayInd<0)
    {
        printf("Invalid index position\n");
    }
    else{
        return sp->arr[arrayInd];
    }
}
int stackBottom(struct stack* sp)
{
    return sp->arr[0];
}
int stackTop(struct stack* sp)
{
    return sp->arr[sp->top];
}
int main()
{
    struct stack* sp = (struct stack*)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 5;
    sp->arr = (int*)malloc(sp->size*sizeof(struct stack));

    printf("Before pushing: Full %d\n", isFull(sp));
    printf("Before pushing: Empty %d\n", isEmpty(sp));

    push(sp, 68);
    push(sp, 12);
    push(sp, 45);
    push(sp, 67);
    push(sp, 78);


    printf("The Popped Element is %d\n", pop(sp));
    printf("The Popped Element is %d\n", pop(sp));
   

    printf("After pushing: Full %d\n", isFull(sp));
    printf("After pushing: Empty %d\n", isEmpty(sp));

    for (int j = 1; j <= sp->top+1; j++)    
    {
        printf("The value at %d position is %d\n", j, peek(sp, j));
    }
    
    printf("The Stack Bottom element is: %d\n", stackBottom(sp));
    printf("The Stack Top element is: %d\n", stackTop(sp));

    
}
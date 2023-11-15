#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *sp, int val)
{
    if (isFull(sp))
    {
        printf("The Stack is Full/Overflow\n");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = val;
    }
}
int pop(struct stack *sp)
{
    int val;
    if (isEmpty(sp))
    {
        printf("The Stack is Empty/Underflow\n");
    }
    else
    {
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
        printf("Not a valid position in stack\n");
        return -1;
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
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * (sizeof(int)));

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));

    push(sp, 23);
    push(sp, 12);
    push(sp, 45);
    push(sp, 56);
    push(sp, 34);
    push(sp, 67);
    push(sp, 78);
    push(sp, 67);
    push(sp, 89);
    push(sp, 89);

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));

    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!


    // PRITING THE VALUES OF STACCK ----> LIKE STACK TRAVERSING
    for(int j=1; j<=sp->top+1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }

    printf("The Bottom element is the stack is %d\n", stackBottom(sp));
    printf("The Top element in the stack is %d\n", stackTop(sp));
    return 0;
}

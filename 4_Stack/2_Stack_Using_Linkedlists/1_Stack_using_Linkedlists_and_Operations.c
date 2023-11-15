#include<stdio.h>
#include<stdlib.h>
struct Node* top = NULL;
struct Node
{
    int data;
    struct Node* next;
};
void stackLinkedListTraversal(struct Node* top)
{
    while(top!=NULL)
    {
        printf("The Element in the stack of linked list is: %d\n", top->data);
        top = top->next;
    }
}
int isEmpty(struct Node* top)
{
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct Node* top)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
struct Node* push(struct Node* top, int data)
{
    if(isFull(top))
    {
        printf("The Stack is Full\n");
    }
    else{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = top;
    top = ptr;
    }
    return top;
}
int pop(struct Node* tp)
{
    if(isEmpty(top)){
        printf("The Stack is Empty\n");
    }
    else{
    struct Node* ptr = top;
    top = top->next;
    int x = ptr->data;
    free(ptr);
     return x;
    }
}
int peek(struct Node* top, int position)
{
    struct Node* ptr = top;
    for (int i = 0;(i < position-1 && ptr!=NULL); i++)
    {
       ptr = ptr->next;
    }
    if(ptr!=NULL)
    {
        return ptr->data;
    }
    else{
        return -1;
    }
}
int stackTop(struct Node* top)
{
    return top->data;
}
int stackBottom(struct Node* top)
{
    struct Node* ptr = top;
    
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}
int main()
{
    top = push(top, 12);
    top = push(top, 13);
    top = push(top, 23);
    // printf("The popped element is %d\n", pop(top));
    stackLinkedListTraversal(top);
    for (int i = 1; i <= 3; i++)
    {
        printf("The Element in the position %d is %d\n", i, peek(top, i));
    }
    printf("The StackTop element in the stack is %d\n", stackTop(top));
    printf("The StackBottom element in the stack is %d\n", stackBottom(top));
    return 0;
}
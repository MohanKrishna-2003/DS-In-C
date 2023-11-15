#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("The element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void enqueue(int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("The Queue is Full\n");
    }
    else
    {
        ptr->data = data;
        ptr->next = NULL;
        if (front == NULL)
        {
            front = rear = ptr;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
        }
    }
}
int dequeue()
{
    int val = -1;
    struct Node* ptr = front;
    if(front==NULL){
        printf("The Queue is Full\n");
    }
    else{
        front = front->next;
        val = ptr->data;
        free(ptr);
    }
    return val;

    
}
int main()
{
    enqueue(12);
    enqueue(67);
    enqueue(45);
    printf("Dequeuing element %d\n", dequeue());
    linkedListTraversal(front);
}
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void linkedListTraversal(struct Node* ptr)
{
    while(ptr!=NULL)
    {
        printf("The element in the linked list is: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int mian()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // ALLOCATION MEMORY FOR NODES IN THE LINKED LIST IN HEAP
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // CREATION OF HEAD/FIRST NODE
    head->data = 3;
    head->next = second;

    // CREATION OF SECOND NODE
    second->data = 6;
    second->next = third;

    // CREATION OF THIRD NODE
    third->data = 9;
    third->next = NULL;

    // TRAVERSAL OF LINKED LIST
    linkedListTraversal(head);

    return 0;
}
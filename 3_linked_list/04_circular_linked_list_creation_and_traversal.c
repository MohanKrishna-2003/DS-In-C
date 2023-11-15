#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void circularLinkedListTraversal(struct Node *head)
{
    struct Node* ptr = head;
    do
    {
        printf(" Element: %d\n", ptr->data);
        ptr = ptr->next;
    }while (ptr != head);
}

int main()
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
    third->next = head;

    // TRAVERSAL OF LINKED LIST
    circularLinkedListTraversal(head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf(" Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// CASE-1 -> DELETING A NODE AT BEGINNING
struct Node* deletionAtFirst(struct Node* head)
{
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// CASE-2 -> DELETING A NODE IN BETWEEN AT GIVEN INDEX
struct Node* deletionAtIndex(struct Node* head, int index)
{
    struct Node* p = head;
    struct Node* q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
    
}

// CASE-3 -> DELETING A NODE AT END OF THE LINKED LIST
struct Node* deletionAtEnd(struct Node*head)
{
    struct Node* p = head;
    struct Node* q = head->next;
    while (q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// CASE-4 -> DELETING A NODE AT GIVEN VALUE IN THE LINKED LIST
struct Node* deletionAtValue(struct Node* head, int value)
{
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->data!=value && q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data==value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
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
    third->next = NULL;

    // TRAVERSAL OF LINKED LIST
    printf("Linked list before deletion:\n");
    linkedListTraversal(head);

    // head = deletionAtFirst(head);
    // head = deletionAtIndex(head, 1);
    // head = deletionAtEnd(head);
    head = deletionAtValue(head, 9);
    printf("Linked list after deletion:\n");
    linkedListTraversal(head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf(" Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// CASE-1: INSERTION OF NODE AT FIRST OF THE LIST
struct Node* insertionAtFirst(struct Node* head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    head->prev = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

// CASE-2, 3: INSERTION OF NODE AT INDEX, NODE IS SAME AS THE SINGLY LINKED LIST

// CASE-4: INSERITON OF NODE AT END OF THE LIST
struct Node* insertionAtEnd(struct Node* head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head->next;
    ptr->data = data;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    ptr->next = NULL;
    ptr->prev = p;
    p->next = ptr;
    return head;
}
struct Node* deletionAtFirst(struct Node* head)
{
    struct Node* p = head;
    head = head->next;
    head->prev = NULL;
    free(p);
    return head;
}
struct Node* deletionAtLast(struct Node* head)
{
    struct Node* p = head;
    struct Node* q = head->next;
    while(q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    q->next = p->next;
    free(q);
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
    head->prev = NULL;
    head->data = 3;
    head->next = second;

    // CREATION OF SECOND NODE
    second->prev = head;
    second->data = 6;
    second->next = third;

    // CREATION OF THIRD NODE
    third->prev = second;
    third->data = 9;
    third->next = NULL;

    // TRAVERSAL OF LINKED LIST
    linkedListTraversal(head);
    // head = insertionAtFirst(head, 23);
    // head = insertionAtEnd(head, 23);
    head = deletionAtLast(head);
    linkedListTraversal(head);

    return 0;
}
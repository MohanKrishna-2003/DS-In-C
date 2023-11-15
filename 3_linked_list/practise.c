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
        printf("The Element in the linked list is: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node* insertionAtFirst(struct Node* head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}
struct Node* insertionAtIndex(struct Node* head, int data, int index)
{
   struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
   struct Node* p = head;
   int i=0;
   while(i!=index-1)
   {
        p = p->next;
        i++;
   }
   ptr->data = data;
   ptr->next = p->next;
   p->next = ptr;
   return head;
}
struct Node* insertionAtEnd(struct Node* head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    return head;
}
struct Node* insertionAtNode(struct Node* head, struct Node* prevNode, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}
struct Node* deletionAtFirst(struct Node* head)
{
    struct Node* p = head;
    head = head->next;
    free(p);
    return head;
}
struct Node* deletionAtIndex(struct Node* head, int index)
{
    struct Node* p = head;
    struct Node* q = head->next;
    for(int i=0; i<index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
struct Node* deletionAtEnd(struct Node* head)
{
    struct Node* p = head;
    struct Node* q = head->next;
    while (q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    q->next = p->next;
    p->next = NULL;
    free(q);
    return head;
    
}
struct Node* deletionAtNodeValue(struct Node* head, int value)
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
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* first = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    head->data = 12;
    head->next = first;
    first->data = 34;
    first->next = second;
    second->data = 23;
    second->next = third;
    third->data = 78;
    third->next = NULL;
    // printf("Linked list before Insertion:\n");
    printf("Linked list before Deletion:\n");
    linkedListTraversal(head);
    // head = insertionAtFirst(head, 68);
    // head = insertionAtIndex(head, 68, 2);
    // head = insertionAtEnd(head, 68);
    // head = insertionAtNode(head, second, 68);
    // head = deletionAtFirst(head);
    // head = deletionAtIndex(head, 2);
    // head = deletionAtEnd(head);
    head = deletionAtNodeValue(head, 23);
    // printf("Linked list after Insertion:\n");
    printf("Linked list after Deletion:\n");
    linkedListTraversal(head);
}
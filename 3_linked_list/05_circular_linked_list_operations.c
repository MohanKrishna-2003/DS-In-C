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

// CASE-1: INSERTION OF NODE AT FIRST
struct Node* insertionAtFirst(struct Node* head, int data)
{
  struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
  ptr->data = data;
  struct Node* p = head->next;
  while(p->next!=head)
  {
    p = p->next;
  }
  p->next = ptr;
  ptr->next = head;
  head = ptr;
  return head;
}

// CASE-2, 3: INSERTION AT GIVEN INDEX, NODE WILL BE SAME AS THE SINGLY LINKED LIST

//CASE-4: INSERTION OF NODE AT END OF THE LIST
struct Node* insertionAtEnd(struct Node* head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node* p = head->next;
    while(p->next!=head)
    {
        p = p->next;
    }
    ptr->next = head;
    p->next = ptr;
    return head;

}

// CASE-1, 2, 3, 4 FOR DELETION WILL BE SAME AS THE SINGLY LINKED LIST
struct Node* deletionAtFirst(struct Node* head)
{
    struct Node* ptr = head;
    struct Node* p = head->next;
    do
    {
        ptr = ptr->next;
    }while(ptr->next!=head);
    ptr->next = p;
    head = p;
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
    third->next = head;

    // TRAVERSAL OF LINKED LIST
    printf("Circular Linked List before insertion operation:\n");
    circularLinkedListTraversal(head);

    // head = insertionAtFirst(head, 23);
    // head = insertionAtEnd(head, 23);
    // head = deletionAtFirst(head);
    head = deletionAtFirst(head);
    head = deletionAtFirst(head);

    printf("Circular Linked List after insertion operation:\n");
    circularLinkedListTraversal(head);

    return 0;
}
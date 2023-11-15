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

// CASE-1 :- INSERTIOIN OF NODE AT THE BEGINNING
struct Node* insertionAtBeginning(struct Node* head, int data)
{
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// CASE-2 :- INSERTION OF NODE IN BETWEEN( INDEX ) THE LINKED LIST
struct Node* insertInBetween(struct Node* head, int data, int index)
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

// CASE-3 :- INSERTION OF NODE AT THE LAST OF THE LINKED LIST
struct Node* insertAtEnd(struct Node* head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    ptr->data = data;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;

}

// CASE-4 :- INSERTION AFTER THE NODE(GIVEN) IN THE LINKED LIST
struct Node* insertAfterNode(struct Node* head, struct Node* prevNode, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
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
    printf("The elements in the linked list before insertion:\n");
    linkedListTraversal(head);

    // head = insertionAtBeginning(head, 100);
    // head = insertInBetween(head, 78, 2);
    // head = insertAtEnd(head, 68);
    head = insertAfterNode(head, second, 89);
    printf("\nThe elements in the linked list after insertion:\n");
    linkedListTraversal(head);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct circularQueue
{
    int size;
    int front;
    int rear;
    int* arr;
};
int isEmpty(struct circularQueue* q)
{
    if(q->front == q->rear){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct circularQueue* q)
{
    if((q->rear+1)%q->size == q->front){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue(struct circularQueue* q, int val)
{
    if(isFull(q)){
        printf("The Queue is Full\n");
    }
    else{
        q->rear = (q->rear+1)%q->size;
        q->arr[q->rear] = val;
    }
}
int dequeue(struct circularQueue* q)
{
    int val = -1;
    if(isEmpty(q)){
        printf("The Queue is Empty\n");
    }
    else{
        q->front = (q->front+1)%q->size;
        val = q->arr[q->front];
    }
    return val;
}
int main()
{
    struct circularQueue q;
    q.size = 5;
    q.front = q.rear = 0;
    q.arr = (int*)malloc(q.size*sizeof(int));

    enqueue(&q, 11);
    enqueue(&q, 12);
    enqueue(&q, 13);
    enqueue(&q, 14);
    enqueue(&q, 15);
    enqueue(&q, 15);
    printf("Dequeuing Element %d\n", dequeue(&q));
    printf("Dequeuing Element %d\n", dequeue(&q));
    printf("Dequeuing Element %d\n", dequeue(&q));
    printf("Dequeuing Element %d\n", dequeue(&q));

    if(isEmpty(&q)){
        printf("Queue is Empty\n");
    }
    if(isFull(&q)){
        printf("Queue is Full\n");
    }

    return 0;

}
#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int* arr;
};
int isFull(struct queue* q)
{
    if(q->rear == q->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct queue* q)
{
    if(q->rear == q->front){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue* q, int val)
{
    if(isFull(q)){
        printf("The Queue is Full\n");
    }
    else{
        q->rear++;
        q->arr[q->rear] = val;
    }
}
int dequeue(struct queue* q)
{
    int val = -1;
    if(isEmpty(q)){
        printf("The Queue is Empty\n");
    }
    else{
        q->front++;
        val = q->arr[q->front];
    }
    return val;
}

int firstVal(struct queue* q)
{
    return q->arr[q->front];
}

int lastVal(struct queue* q)
{
    return q->arr[q->rear];
}

int peek(struct queue* q, int i)
{
    int arrayInd = q->rear-i+1;
    if(arrayInd<0)
    {
        printf("Not a valid position in queue\n");
        return -1;
    }
    else{
        return q->arr[arrayInd];
    }
}
int main()
{
    struct queue q;
    q.size = 10;
    q.front = -1;
    q.rear = -1;
    q.arr = (int*)malloc(q.size*sizeof(int));

    // Enqueue few elements
    enqueue(&q, 23);
    enqueue(&q, 90);
    enqueue(&q, 12);
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));

    if(isEmpty(&q)){
        printf("Queue is Empty\n");
    }
    if(isFull(&q)){
        printf("Queue is full\n");
    }
    return 0;

}
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5

typedef struct Queue{
    int front;
    int rear;
    int data[MAXSIZE];
}Queue;

Queue* initQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    return q;
}

int isFull(Queue* q){
    if((q->rear + 1) % MAXSIZE == q->front)
        return 1;
    return 0;
}

void enQueue(Queue* q, int data){
    if(isFull(q)){
        return;
    }
    else{
        q->data[q->rear] = data;
        q->rear = (q->rear + 1) % MAXSIZE;
    }
}

int isEmpty(Queue* q){
    if(q->front == q->rear)
        return 1;
    return 0;
}

int deQueue(Queue* q){
    if(isEmpty(q)){
        return -1;
    }
    else{
        int res = q->data[q->front];
        q->front = (q->front + 1) % MAXSIZE;
        return res;
    }
}

void printQueue(Queue* q){
    int length = (q->rear - q->front + MAXSIZE) % MAXSIZE;
    for(int i = 0; i < length; i++){
        printf("%d->", q->data[q->front]);
        q->front = (q->front + 1) % MAXSIZE;
    }
    printf("NULL\n");
}

int main(){
    Queue* q = initQueue();
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    int res = deQueue(q);
    printf("num = %d\n", res);
    printQueue(q);
    return 0;
}
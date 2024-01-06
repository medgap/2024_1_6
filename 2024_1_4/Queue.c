#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int data;
    struct Queue* next;
}Queue;

Queue* initQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = 0;
    q->next = NULL;
    return q;
}

void enQueue(Queue* Q, int data){
    Queue* q = Q;
    Queue* node = (Queue*)malloc(sizeof(Queue));
    node->data = data;
    for(int i = 0; i < Q->data; i++){
        q = q->next;
    }
    node->next = q->next;
    q->next = node;
    Q->data++;
}

int isEmpty(Queue* q){
    if(q->data == 0 || q->next == NULL)
        return 1;
    return 0;
}

int deQueue(Queue* q){
    if(isEmpty(q)){
        return -1;
    }
    else{
        Queue* node = q->next;
        int data = node->data;
        q->next = node->next;
        free(node);
        q->data--;
        return data;
    }
}

void printQueue(Queue* q){
    Queue* node = q->next;
    while(node){
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(){
    Queue* q = initQueue();
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);
    printQueue(q);
    return 0;
}
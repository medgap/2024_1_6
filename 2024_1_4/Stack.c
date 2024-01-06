#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initStack(){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = 0;
    node->next = NULL;
    return node;
}

int isEmpty(Node* S){
    if(S->data == 0 || S->next == NULL)
        return 1;
    return 0;
}

int pop(Node* S){
    if(isEmpty(S)){
        return -1;
    }
    else{
        Node* node = S->next;
        int data = node->data;
        S->next = node->next;
        free(node);
        S->data--;
        return data;
    }
}

void push(Node* S, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = S->next;
    S->next = node;
    S->data++;
}

void print(Node* S){
    Node* node = S->next;
    while(node){
        printf("%d->", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main(){
    Node* node = initStack();
    push(node, 1);
    push(node, 2);
    push(node, 3);
    push(node, 4);
    int num = pop(node);
    printf("num = %d\n", num);
    print(node);
    return 0;
}
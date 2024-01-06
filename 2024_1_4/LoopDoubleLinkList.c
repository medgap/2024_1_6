#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node{
    int data;
    struct Node* pre;
    struct Node* next;
}Node;

Node* initNode(){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = 0;
    node->pre = node;
    node->next = node;
    return node;
}

void headInsert(Node* list, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->pre = list;
    node->next = list->next;
    node->next->pre = node;
    list->next = node;
    list->data++;
}

void tailInsert(Node* list, int data){
    Node* head = list;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    while(list->next != head){
        list = list->next;
    }
    node->next = list->next;
    node->pre = list;
    list->next = node;
    head->pre = node;
}

int delete(Node* list, int data){
    Node* node = list->next;
    while(node != list){
        if(node->data == data){
            node->pre->next = node->next;
            node->next->pre = node->pre;
            free(node);
            list->data--;
            return TRUE;
        }
        node = node->next;
    }
    return FALSE;
}

void print(Node* list){
    Node* node = list->next;
    while(node != list){
        printf("%d->", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    Node* node = initNode();
    headInsert(node, 1);
    headInsert(node, 2);
    headInsert(node, 3);
    headInsert(node, 4);
    headInsert(node, 5);
    tailInsert(node, 6);
    tailInsert(node, 7);
    tailInsert(node, 8);
    tailInsert(node, 9);
    tailInsert(node, 10);
    delete(node, 5);
    delete(node, 3);
    print(node);
    return 0;
}
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
    node->pre = NULL;
    node->next = NULL;
    return node;
}

void headInsert(Node* list, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    if(list->next){
        node->pre = list;
        node->next = list->next;
        list->next->pre = node;
        list->next = node;
    }
    else{
        node->next = list->next;
        list->next = node;
        node->pre = list;
    }
    list->data++;
}

void tailInsert(Node* list, int data){
    Node* head = list;
    Node* node = (Node*)malloc(sizeof(Node));
    while(list->next){
        list = list->next;
    }
    node->data = data;
    node->pre = list;
    node->next = list->next;
    list->next = node;
    head->data++;
}

int delete(Node* list,int data){
	Node* curNode = list->next;
	while(curNode){
		if(curNode->data == data){
			//删除节点 
			if(curNode->next != NULL){
			curNode->pre->next = curNode->next; 
			curNode->next->pre = curNode->pre;
			free(curNode);
			list->data--;
		}else{
			curNode->pre->next = NULL; 
			free(curNode);
			list->data--;
		}
			return TRUE;
			
		}
		curNode = curNode->next; 
	}
	return FALSE; 
	
}

void print(Node* list){
    Node* node = list->next;
    while(node){
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
    delete(node, 8);
    print(node);
    return 0;
}
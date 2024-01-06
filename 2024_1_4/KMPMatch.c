#include<stdio.h>
#include<stdlib.h>

typedef struct String{
    char* data;
    int len;
}String;

String* initString(){
    String* s = (String*)malloc(sizeof(String));
    s->data = NULL;
    s->len = 0;
    return s;
}

void StringAssign(String* s, char* data){
    if(s->data){
        free(s->data);
    }
    else{
        char* temp = data;
        int len = 0;
        while(*temp){
            len++;
            temp++;
        }
        temp = data;
        s->len = len;
        s->data = (char*)malloc(sizeof(char) * (len + 1));
        for(int i = 0; i < s->len; i++, temp++){
            s->data[i] = *temp;
        }
    }
}

int* getNext(String* s){
    int i = 0;
    int j = -1;
    int* next = (int*)malloc(sizeof(int) * s->len);
    next[i] = j;
    while(i < s->len - 1){
        if(j == -1 || s->data[i] == s->data[j]){
            next[++i] = ++j;
        }
        else{
            j = next[j];
        }
    }
    return next;
}

void kmpMatch(String* master, String* sub, int* next){
    int i = 0;
    int j = 0;
    while(i < master->len && j < sub->len){
        if(j == -1 || master->data[i] == sub->data[j]){
            i++;
            j++;
        }
        else{
            j = next[j];
        }
    }
    if(j == sub->len){
        printf("match success");
    }
    else{
        printf("match fail");
    }
}

int main(){
    String* s1 = initString();
    String* s2 = initString();
    StringAssign(s1, "ababdc");
    StringAssign(s2, "abc");
    int* next = getNext(s2);
    kmpMatch(s1, s2, next);
    return 0;
}
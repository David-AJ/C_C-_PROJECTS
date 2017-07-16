#include<iostream>
using namespace std;
#include<vector>
#include<map>

struct List {
    int value;
    List *next;
    List(int val):value(val),next(NULL){}
};

void printList(List *a){
    while(a){
        printf("%d  ",a->value);
        a = a->next;
    }
    printf("\n");
}

int len(List *a){
    int len = 1;
    List *next = a->next;
    while(next != NULL){
        len++;
        next = next->next;
    }
    return len;
}


List* reverse(List *a){
    List *pre = NULL;
    List *next;
    while(a){
        next = a->next;
        a->next = pre;
        pre = a;
        a = next;
    }
    return pre;
}

List* CreateList(int len){
    List *q = new List(0);
    List *a = q;
    for(int i=1;i<len;i++){
        List *p = new List(i);
        q->next = p;
        q = p;
    }
    return a;
}


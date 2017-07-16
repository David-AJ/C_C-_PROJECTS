#include<iostream>
#include "List.h"

using namespace std;

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

int main() {
    //创建一个List
    List *a = CreateList(6);

    printf("创建List: \n");
    printList(a);
    //转置List
    a = reverse(a);

    printf("转置后: \n");
    printList(a);
    cout<<"length of List:"<<" "<<len(a)<<endl;

    return 0;
}

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
    //����һ��List
    List *a = CreateList(6);

    printf("����List: \n");
    printList(a);
    //ת��List
    a = reverse(a);

    printf("ת�ú�: \n");
    printList(a);
    cout<<"length of List:"<<" "<<len(a)<<endl;

    return 0;
}

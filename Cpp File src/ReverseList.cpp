#include<cstdio>
#include "List.h"


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
    printf("�������б��ȣ� \n");
    int num;
    scanf("%d",&num);
    //����һ��List
    List *a = CreateList(num);
    printf("����List: \n");
    printList(a);
    //ת��List
    a = reverse(a);
    printf("ת�ú�: \n");
    printList(a);
    printf("length of List: %d",len(a));

    return 0;
}

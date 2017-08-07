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
    printf("请输入列表长度： \n");
    int num;
    scanf("%d",&num);
    //创建一个List
    List *a = CreateList(num);
    printf("创建List: \n");
    printList(a);
    //转置List
    a = reverse(a);
    printf("转置后: \n");
    printList(a);
    printf("length of List: %d",len(a));

    return 0;
}

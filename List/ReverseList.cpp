#include<iostream>
#include "List.h"

using namespace std;


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

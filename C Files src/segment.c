#include<stdio.h>
#include<string.h>

int countSegments(char* s) {
    int len = strlen(s), count = 0;
    for(int i=1;i<len;i++){
        if(*(s+i)!=' '&&*(s+i-1)==' ') count++;
    }
    if(*s!=' '&&len!=0) count++;
    return count;
}

int main(){
    char input[100] = {NULL};
    printf("�������ַ��������ӣ�Hello, my name is John����\n");
    gets(input);
    printf("Number of Segment is(5): %d",countSegments(input));
    return 0;
}

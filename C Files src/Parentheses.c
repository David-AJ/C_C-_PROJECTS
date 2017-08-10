#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

const char* bol[2] = {"false","true"};
bool isValid(char* s) {
    int len = strlen(s), size = 0;
    if(len%2!=0) return false;
    int check[150] = {NULL};
    check[')'] = '(';
    check['}'] = '{';
    check[']'] = '[';
    char* stack = (char*)malloc(sizeof(char)*len/2);
    memset(stack,0,sizeof(char)*len/2);
    for(int i=0;i<len;i++){
        if(*(s+i)==')'||*(s+i)==']'||*(s+i)=='}'){
            if(size<=0) return false;
            size -= 1;
            if(stack[size]!=check[*(s+i)]) return false;
        }
        else stack[size++] = *(s+i);
    }
    if(size!=0) return false;
    return true;
}

int main(){
    char* t1 = "[";
    char* t2 = "([)";    
    char* t3 = "{[([])]}";
    printf("test1:'%s'\nanswer:%s\ntest2:'%s'\nanswer:%s\ntest3:'%s'\nanswer:%s",
            t1,bol[isValid(t1)],t2,bol[isValid(t2)],t3,bol[isValid(t3)]);
    return 0;
}
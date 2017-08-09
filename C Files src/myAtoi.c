#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int myAtoi(char* str) {
    int len = strlen(str), count = 0, tag = 1;
    int a[100]={NULL};
    if(!strcmp(str,"")) return 0;
    int i = 0;
    while(str[i]==' ') i++;
    if(str[i]=='-'||str[i]=='+'||(str[i]<='9'&&str[i]>='0')) {
        if(str[i]=='-') {
            tag = -1;
            i++;
        }
        else if (str[i]=='+') i++;
        while(str[i]<='9'&&str[i]>='0'){
            a[count++] = str[i]-'0';
            i++;
        }
    }
    else return 0;
    long long result = 0;
    int j= 0;
    while(j<count&&result<INT_MAX){
        result = result*10 + a[j];
        j++;
    }
    result *= tag;
    result = result>=INT_MAX?INT_MAX:result;
    return result<=INT_MIN?INT_MIN:result;
}

int main(){
    char* t1 = "18446744073709551617";
    char* t2 = "9223372036854775809";
    char* t3 = "2147483648";
    char* t4 = "-123";
    char* t5 = "+5600";
    char* t6 = "+-14";
    printf("test1:'%s'\nanswer:%d\ntest2:'%s'\nanswer:%d\ntest3:'%s'\nanswer:%d\
    \ntest4:'%s'\nanswer:%d\ntest5:'%s'\nanswer:%d\ntest6:'%s'\nanswer:%d",
            t1,myAtoi(t1),t2,myAtoi(t2),t3,myAtoi(t3),t4,myAtoi(t4),t5,myAtoi(t5),t6,myAtoi(t6));
    return 0;
}
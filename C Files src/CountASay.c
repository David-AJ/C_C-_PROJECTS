#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char temp[8000] = {NULL};
char s[8000] = {NULL};
char* countAndSay(int n) {
    if(n<=4){
        switch(n){
            case 1: strcpy(s,"1"); break;
            case 2: strcpy(s,"11"); break;
            case 3: strcpy(s,"21"); break;
            case 4: strcpy(s,"1211"); break;
        }
        return s;
    }
    else {
        strcpy(temp,countAndSay(n-1));
        int len = strlen(temp), index = 0, i = 0; 
        while(i<len-2){
            if(*(temp+i)==*(temp+i+1)){
                if(*(temp+i+1)!=*(temp+i+2)){
                    s[index++] = '2';
                    s[index++] = *(temp+i);
                    i += 2;
                }
                else {
                    s[index++] = '3';
                    s[index++] = *(temp+i);
                    i += 3;
                }
            }
            else {
                s[index++] = '1';
                s[index++] = *(temp+i);
                i += 1;
            }
        }
        if(i==len-1){
            s[index++] = '1';
            s[index] = *(temp+i);
        }
        else if(i==len-2){
            if(*(temp+i)==*(temp+i+1)){
                s[index++] = '2';
                s[index] = *(temp+i);
            }
            else {
                s[index++] = '1';
                s[index++] = *(temp+(i++));
                s[index++] = '1';
                s[index] = *(temp+i);
            }
        }
        return s;
    }

}

int main(){
    int n;
    printf("ÇëÊäÈën(5): \n");
    scanf("%d",&n);
    printf("(111221): %s",countAndSay(n));
    return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int strStr(char* haystack, char* needle) {
    int hlen = strlen(haystack), nlen = strlen(needle);
    if (nlen==0) return 0;
    char temp = needle[0];
    for(int i=0;i<hlen-nlen;i++){
        if(*(haystack+i)==temp){
            if(!strncmp(needle,haystack+i,nlen)) return i;
        }
    }
    return -1;
}

int main(){
    char* str1 = "mississippi";
    char* str2 = "issip";
    int a = strStr(str1,str2);
    printf("input: ['%s','%s']\noutpu: %d",str1,str2,a);
    return 0;
}
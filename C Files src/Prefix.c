#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

char* PR1(char** strs, int strsSize) {
    if(strsSize==0) return "";
    char* re = (char*)malloc(sizeof(char)*1000);
    memset(re,0,sizeof(char)*1000);
    strcpy(re,strs[0]);
    int len = strlen(re);
    for(int i=1;i<strsSize;i++){
        while(strstr(strs[i],re)!=strs[i]){
            len--;
            if (len==-1) return "";
            re[len] = 0;
        }
    }
    return re;
}

char* PR2(char** strs, int strsSize) {
    int min = INT_MAX;
    for(int i=0;i<strsSize;i++){
        if (min>strlen(strs[i])) min=strlen(strs[i]);
    }
    if(strsSize==0) return "";
    char* re = (char*)malloc(sizeof(char)*100);
    memset(re,0,sizeof(char)*100);
    char temp;
    for(int i=0;i<min;i++){
        temp = strs[0][i];
        for(int j=1;j<strsSize;j++){
            if (temp!=strs[j][i]) return re;
        }
        re[i] = strs[0][i];
    }
    return re;
}

int main(){
    char* a[] = {"flower","flow","flight"};
    char* r1 = PR1(a,sizeof(a)/sizeof(char*));
    char* r2 = PR2(a,sizeof(a)/sizeof(char*));
    printf("input: ['%s','%s','%s']\noutput1: %s\noutput2: %s",a[0],a[1],a[2],r1,r1);
    return 0;
}
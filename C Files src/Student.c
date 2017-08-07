#include<string.h>
#include<stdio.h>

char* bol[] = {"false","ture"};

bool checkRecord(char* s) {
    int count_A = 0, len = strlen(s);
    if(strstr(s,"LLL")) return false;
    for(int i=0;i<len;i++){
        if(*(s+i)=='A') count_A++;
        if(count_A>1) return false;
    }
    return true;
}

int main(){
    printf("ÇëÊäÈë×Ö·û´®£º\n");
    char input[100] = {NULL};
    gets(input);
    printf("%s is no more than one 'A' (absent) or two continuous 'L' (late):\n%s",input,bol[checkRecord(input)]);
    return 0;
}

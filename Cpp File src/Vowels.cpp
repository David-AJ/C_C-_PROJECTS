#include<cstring>
#include<cstdio>

bool isVowels(char s){
    if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u'||s=='A'||s=='E'||s=='I'||s=='O'||s=='U'){
        return true;
    }
    return false;
}

char* reverseVowels(char* s) {
    int i=0,j = strlen(s)-1;
    while(i<=j){
        if(!isVowels(*(s+i))){
            i++;
            continue;
        }
        if(!isVowels(*(s+j))){
            j--;
            continue;
        }
        char temp = *(s+i);
        *(s+i) = *(s+j);
        *(s+j) = temp;
        i++;
        j--;
    }
    return s;
}

int main(){
    char input[100] = {NULL};
    printf("请输入字符串（例子：shAeio）：\n");
    gets(input);
    char* str = reverseStr(input,k);
    printf("结果（正确答案：shoieA）：\n%s",str);
    return 0;    
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

int lengthOfLastWord(char* s) {
    int len = strlen(s), count = 0;
    while(!isalpha(s[len])&&len>=0){
        len--;
    }
    if (len==-1) return 0;
    while(isalpha(s[len])&&len>=0){
        count++;
        len--;
    }
    return count;
}

int main(){
    char input[100] = {NULL};
    printf("ÇëÊäÈë£º ");
    gets(input);
    printf("´ğ°¸£º %d",lengthOfLastWord(input));
    return 0;
}
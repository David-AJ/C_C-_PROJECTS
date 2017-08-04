#include<cstdio>
#include<cstring>

char* reverseWords(char* s) {
    int len = strlen(s), end = 0, now = 0;
    char temp;
    while(end<len){
        if(*(s+end)==' '){
            for(int i=0;i<(end-now)/2;i++){
                temp = *(s+now+i);
                *(s+now+i) = *(s+end-1-i);
                *(s+end-1-i) = temp;
            }
            end++;
            now=end;
        }
        else if(end==len-1){
            for(int i=0;i<(end-now+1)/2;i++){
                temp = *(s+now+i);
                *(s+now+i) = *(s+end-i);
                *(s+end-i) = temp;
            }
            end++;
        }
        else end++;
    }
    return s;
}

int main(){
    char input[80] ={NULL};
    gets(input);
    char* r = reverseWords(input);
    printf("%s",r);
    return 0;
}
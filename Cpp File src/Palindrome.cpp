#include<cstdio>
#include<cctype>
#include<cstring>

bool isPalindrome(char* s) {
    int right = strlen(s)-1,left = 0;
    if(!strcmp(s,"")||right==0){
        return 1;
    }
    do{
        if(!isalnum(s[left])){
            left++;
            continue;
        }
        if(!isalnum(s[right])){
            right--;
            continue;
        }
        if(toupper(s[left])==toupper(s[right])){
            right--;
            left++;
            continue;
        }
        return 0;
    }while(left+1<=right);
    return 1;
}

int main(){
    char* test = "ab2a";
    printf("%d",isPalindrome(test));
    return 0;
}
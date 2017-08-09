#include<cstdio>
#include<cstring>

const char* bol[] = {"false","ture"};

bool repeatedSubstringPattern(char* s) {
    int len = strlen(s),times;
    char pattern[5001] = {NULL};
    char temp[5001] = {NULL};
    pattern[0] = s[0];
    for(int i=1;i<=len/2;i++){
        if(s[i]==pattern[0]&&len%i==0){
            times = len/i;
            strncpy(pattern,s,i);
            int tag = 0;
            for(int j=1;j<times;j++){
                strncpy(temp,s+j*i,i);
                if(strncmp(temp,pattern,i)){
                    tag = 1;
                    break;
                }
            }
            if(tag) continue;
            else return true;
        }
    }
    return false;
}

int main(){
    char input[100] = {NULL};
    printf("���ӣ�abcabcabcacb\ntrue\n�����룺");
    gets(input);
    printf("%s",bol[repeatedSubstringPattern(input)]);
    return 0;
}

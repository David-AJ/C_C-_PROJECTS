#include<cstring>
#include<cstdio>
#include<cctype>

char* reverseStr(char* s, int k) {
    int len = strlen(s),index = 0;
    char temp;
    if(k>=len){
        for(int i=0;i<len/2;i++){
            temp = s[i];
            s[i] = s[len-1-i];
            s[len-1-i] = temp;
        }
        return s;
    }
    if(k*2>=len){
        for(int i=0;i<k/2;i++){
            temp = s[i];
            s[i] = s[k-1-i];
            s[k-1-i] = temp;
        }
        return s;
    }
    int times = len/(2*k);
    if(len%(2*k)<=k){
        for(int index=0;index<times;index++){
            for(int i=0;i<k/2;i++){
                temp = s[i+index*2*k];
                s[i+index*2*k] = s[index*2*k+k-1-i];
                s[index*2*k+k-1-i] = temp;
            }
        }
        for(int i=0;i<(len-times*2*k)/2;i++){
            temp = s[i+times*2*k];
            s[i+times*2*k] = s[len-1-i];
            s[len-1-i] = temp;
        }
    }
    else{
        for(int index=0;index<=times;index++){
            for(int i=0;i<k/2;i++){
                temp = s[i+index*2*k];
                s[i+index*2*k] = s[index*2*k+k-1-i];
                s[index*2*k+k-1-i] = temp;
            }
        }
    }
    return s;
}

int main(){
    char input[100] = {NULL};
    printf("请输入字符串（例子：abcdefge）：\n");
    gets(input);
    int k;
    printf("请输入数字：\n");
    scanf("%d",&k);
    char* str = reverseStr(input,k);
    printf("结果（正确答案：cbadefeg）：\n%s",str);
    return 0;
}
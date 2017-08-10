#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

char* addBinary(char* a, char* b) {
    int len_a = strlen(a), len_b = strlen(b);
    int MAX = len_a>len_b?len_a:len_b;
    int int_a, int_b, next = 0;
    char* B = (char*)malloc(sizeof(char)*(MAX+2));
    memset(B,0,sizeof(char)*(MAX+2));
    len_a--;
    len_b--;
    while(len_a>=0||len_b>=0){
        int_a = len_a>=0? *(a+len_a--)-'0':0;
        int_b = len_b>=0? *(b+len_b--)-'0':0;
        if (int_a+int_b+next<2){
            B[MAX--] = int_a+int_b+next+'0';
            next = 0;
        }
        else {
            if (int_a+int_b+next==2){
                B[MAX--] = '0';
                next = 1;
            }
            else {
                B[MAX--] = '1';
                next = 1;
            }
        }
    }
    if(next) B[0] = '1';
    else return B+1;
    return B;    
}


int main(){
    char* a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
    char* b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
    char* re = addBinary(a,b);
    printf("input_1: %s\ninput_2: %s\nanswer: %s",a,b,re);
    return 0;
}
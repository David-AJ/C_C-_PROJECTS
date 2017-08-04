#include<cstdio>
#include<cstring>

bool IsCapital(const char* word) {
    int start,end,BIG=1,SMALL=0;
    int len = strlen(word);
    int i = 0;
    if(*(word+i)>'Z') {
        start = end = SMALL;
        for(i=1;i<len;i++){
            if(*(word+i)<='Z'){
                end = BIG;
                return false;
            }
        }
        return true;
    }
    else {
        start = *(word+i+1)<='Z'?BIG:SMALL;
        for(i=2;i<len;i++){
            if((*(word+i)>'Z'?SMALL:BIG)!=start){
                return false;
            }
        }
        return true;
    }
}

int main(){
    const char* a = "SHIT";
    const char* b = "ShIT";
    const char* c = "Google";
    printf("For a '%s': %d\nFor b '%s': %d\nFor c '%s': %d",a,IsCapital(a),b,IsCapital(b),c,IsCapital(c));
    return 0; 
}
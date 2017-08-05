#include<cstring>
#include<cstdio>
#include<cctype>

const char* b[2] = {"fasle","true"};

bool canConstruct(char* ransomNote, char* magazine) {
    int ransize = strlen(ransomNote), magsize = strlen(magazine);
    int c_r[26] = {0};
    int c_m[26] = {0};
    for(int i=0; i<ransize; i++) c_r[ransomNote[i]-'a'] += 1;
    for(int j=0; j<magsize; j++) c_m[magazine[j]-'a'] += 1;
    for(int k=0; k<26; k++){
        if(c_r[k]>c_m[k]) return false;
    }
    return true;
}

int main(){
    char* t1 = "eba";
    char* t2 = "aacbed";
    printf("ransomNote: %s\nmagazine: %s\n%s\n",t1,t2,b[canConstruct(t1,t2)]);
    char ran[80] = {NULL};
    char maga[1000] = {NULL};
    printf("ransomNote: ");
    gets(ran);
    printf("magazine: ");
    gets(maga);
    printf("%s",b[canConstruct(ran,maga)]);
    return 0;
}
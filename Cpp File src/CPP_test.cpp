#include<cstdio>
#include<cstring>


int main(){
    double a_db = 1.0;
    int a_int = 1;
    bool a_bool = 1;
    float a_fl = 1.2;
    char* a_ch[3] = {NULL};
    char* k = "abc";
    a_ch[2] = k;
    printf("double: %d, int: %d, bool: %d, float: %d, char: %d, str: %s",
    sizeof(a_db),sizeof(a_int),sizeof(a_bool),sizeof(a_fl),strlen(a_ch[2]),a_ch[2]);
    return 0;
}

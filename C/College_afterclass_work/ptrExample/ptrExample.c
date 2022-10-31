#include <stdio.h>

int main(){
    int *pa = NULL;
    int a = 114514;
    printf("变量a现在等于:%d", a);
    pa = &a;
    *pa = 1919810;
    printf("变量a现在等于:%d", a);
    return 0;
}
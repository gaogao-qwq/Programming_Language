#include <stdio.h>
int main()
{
    char a = 'F';
    int f = 123;

    char *pa = &a;
    int *pf = &f;  //获取变量的地址并将其存放至对应的指针变量中

    printf("a = %c\n", *pa);
    printf("f = %d\n", *pf);
    
    getchar();
    return 0;
}
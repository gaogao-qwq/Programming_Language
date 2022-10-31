#include <stdio.h>

/*The function scanf() is a piece of sh*t.*/

int main(){
    int a, b;
    float x, y;
    char c1, c2;
    scanf("%d%d", &a, &b);
    scanf("%f%f", &x, &y);
    getchar();              //getchar() is used to delete \n from stdin, so that stupid scanf() won't read that \n.
    scanf("%c%c", &c1, &c2);

    printf("a=%d,b=%d\n",a , b);
    printf("x=%.1f,y=%.2f\n", x, y);
    printf("a+b=%d\n", (a + b));
    printf("x+y=%.2f\n", (x + y));
    printf("a/b=%.6f\n", (float)a / (float)b);   //Note that the division of integer variables in C is still integer variables.

    printf("c1=%c   ASCII:%d",c1, c1);
    printf("c2=%c   ASCII:%d",c2, c2);
    return 0;
}
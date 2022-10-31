#include <stdio.h>

int main(){

    int *p1, *p2;
    int a = 5, b = 9, c;
    p1 = &a;
    p2 = &b;
    c = *p1;
    *p1 = *p2;
    *p2 = c;

    return 0;
}
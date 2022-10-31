#include <stdio.h>

int main(){
    void swap(int *p1, int *p2);
    int a, b;
    int *pointer_1, *pointer_2;
    scanf("%d,%d", &a, &b);
    pointer_1 = &a;
    pointer_2 = &b;
    swap(pointer_1, pointer_2);
    printf("a=%d,b=%d", a, b);
    return 0;
}

void swap(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
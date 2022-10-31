#include <stdio.h>

void swap(int *x, int *y);

int main(){
    int x = 1, y = 2;
    swap(&x, &y);
    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
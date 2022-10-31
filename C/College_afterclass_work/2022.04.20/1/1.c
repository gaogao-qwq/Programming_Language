#include <stdio.h>

int main(){
    int num[10];
    int min;
    int min_th;

    for (int i = 0; i < 10; i++)
    {
        printf("Please enter %dth numbers:", i + 1);
        scanf("%d", &num[i]);
    }
    min = num[0];
    min_th = 1;
    for (int i = 1; i < 10; i++)
    {
        if (num[i] < min)
        {
            min = num[i];
            min_th = i + 1;
        }
    }
    printf("The min num is:%d\nIt is %dth num", min, min_th);

    return 0;
}
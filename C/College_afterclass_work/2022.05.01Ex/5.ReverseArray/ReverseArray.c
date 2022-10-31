#include<stdio.h>
#include<string.h>

int main(){
    void swap();
    int arr[9];
    int len = sizeof(arr) / sizeof(arr[0]);
    int mid = len / 2;

    printf("Please enter the array:\n");
    for (size_t i = 0; i < len; i++)
    {
        printf("enter arr[%d]:", i);
        scanf("%d", &arr[i]);
    }
    printf("The array is:\n");
    for (size_t i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    for (int i = 0, j = 8; i != j; i++, j--)
    {
        swap(&arr[i],&arr[j]);
    }
    printf("\n");
    printf("The reversed array is:\n");
    for (size_t i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
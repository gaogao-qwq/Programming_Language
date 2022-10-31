#include <stdio.h>
#include <stdbool.h>

void convert(int arr[][3]);
void printArr(int arr[][3]);
void inputArr(int arr[][3]);
void swap(int *x, int *y);
int arr[3][3];

int main(){
    printf("Please enter Array:\n");
    inputArr(arr);
    printf("\nOriginal Array is:\n");
    printArr(arr);

    convert(arr);

    printf("\nConverted Array is:\n");
    printArr(arr);
    return 0;
}

//行列互换函数
void convert(int arr[][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            swap(&arr[i][j], &arr[j][i]);
        }
    }
}

//打印数组函数
void printArr(int arr[][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}

//输入数组函数
void inputArr(int arr[][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

//交换函数
void swap(int *x, int *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}
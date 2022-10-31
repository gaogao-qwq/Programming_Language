#include <stdio.h>
#include <string.h>

int main(){
    int arr[3][3], sum = 0;
    printf("Please enter num of 3*3 matrix:\n");
    for (size_t x = 0; x < 3; x++)
    {
        for (size_t y = 0; y < 3; y++)
        {
            printf("arr[%d][%d]:", x, y);
            scanf("%d",&arr[x][y]);
        }
    }
    for (size_t i = 0; i < 3; i++)
    {
        sum += arr[i][i];
    }
    printf("The sum is:%d", sum);
    return 0;
}
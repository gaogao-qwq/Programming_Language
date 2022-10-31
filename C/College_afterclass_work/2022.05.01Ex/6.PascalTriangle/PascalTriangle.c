#include <stdio.h>
#include <string.h>

int main(){
    int arr[10][10];
    for (int i = 0; i < 10; i++)
    {
        arr[i][i] = 1;
        arr[i][0] = 1;
    }
    for (int i = 2,j = 1; i < 10; i++, j = 1)
    {
        do
        {
            arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
            j++;
        } while (j < i);
    }
    printf("%5d\n%5d%5d\n", arr[0][0], arr[1][0], arr[1][1]);
    for (int i = 2,j = 0; i < 10; i++, j = 0)
    {
        while (i + 1 != j)
        {
            printf("%5d", arr[i][j]);
            j++;
            if (i + 1 == j)
            {
                printf("\n");
            }
        } 
    }
    return 0;
}
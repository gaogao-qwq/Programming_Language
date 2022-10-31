#include <stdio.h>
#include <string.h>

int main(){
    void condition();
    int arr[99][99], n;
    
    printf("Please enter an odd var n(1 ~ 99):");//输入数组大小
    scanf("%d", &n);
    while (n < 1 || n > 99 || n % 2 == 0)
    {
        printf("Please enter an odd var n(1 ~ 99):");
        scanf("%d", &n);
    }
    int mid = n / 2;

    //初始化数组
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    arr[0][mid] = 1;
    //判断实现
    for (int i = 0, j = mid, x, y, sum = n * n, num = 2; num <= sum; num++)
    {
        condition(i, j, n, &x, &y);
        if (arr[x][y] == 0)
        {
            arr[x][y] = num;
            i = x, j = y;
        }
        else
        {
            i++;
            arr[i][j] = num;
            x = i, y = j;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%5d",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//越界判断函数
void condition(int i, int j, int n, int *x, int *y)
{
    if (i - 1 >= 0 && j + 1 < n)//i,j不越界
    {
        i--, j++;
    }
    else if (i - 1 < 0 && j + 1 >= n)//i,j均越界
    {
        i += (n - 1), j -= (n - 1);
    }
    else if (i - 1 < 0)//i越界
    {
        i += (n - 1), j++;
    }
    else if (j + 1 >= n)//j越界
    {
        i--, j -= (n - 1);
    }
    *x = i, *y = j;
}
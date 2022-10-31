#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//只能求得一个鞍点，可以求得多个的在2
int main()
{
    int arr[99][99], res[9801], x[9801], y[9801], count = 0, size = 3;
    bool isSaddle;
    time_t t;
    srand((unsigned) time(&t));//初始化随机数生成器

    do
    {
        printf("Please enter the size of the martrix(1 ~ 99):");//输入数组大小
        scanf("%d", &size);
    } while (size < 1 || size > 99);
    
    //初始化数组
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }


    for (int i = 0, max_j, min_i; i < size; i++)
    {
        min_i = i, max_j = 0;
        int max = arr[i][0];
        isSaddle = true;
        for (int j = 0; j < size; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                max_j = j;
            }
        }
        for (int i_ = 0; i_ < size; i_++)
        {
            if (max > arr[i_][max_j])
            {
                isSaddle = false;
                break;
            }
        }
        if (isSaddle)
        {
            res[count] = max;
            x[count] = min_i;
            y[count] = max_j;
            count++;
        }
    }
    
    if (count > 0)
    {
        for (int i = 0; i < count; i++)
        {
            printf("arr[%d][%d] = %d", x[i], y[i], res[i]);
        }
    }
    else
    {
        printf("There is no saddle point.");
    }
    return 0;
}

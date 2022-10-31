#include <stdio.h>
#include <string.h>

int main(){
    int arr[11] = {11, 31, 54, 125, 364, 378, 412, 654, 780, 999};
    int num;
    int cache;
    printf("enter a num:");
    scanf("%d", &num);
    if (num > arr[9])
    {
        arr[10] = num;
    }
    else
    {
        for (size_t i = 8; i > 0; i--)
        {
            if (num > arr[i])
            {
                cache = arr[i + 1];
                arr[i + 1] = num;
                for (size_t j = 9; j > i; j--)
                {
                    arr[j + 1] = arr[j];
                }
                arr[i + 2] = cache;
                break;
            }
            
        }
    }
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

int main(){
    void swap();
    int num[10] = {29, 65, 75, 80, 4, 65, 42, 11, 45, 73};
    int min;
    for (size_t i = 0; i < 9; i++)
    {
        for (size_t j = i; j < 10; j++)
        {
            if (num[j] < num[min])
            {
                min = j;
            }
            swap(&num[min], &num[i]);
        }
    }
    for (size_t i = 0; i < 9; i++)
    {
        printf("%d ", num[i]);
    }
    return 0;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

    for (int narcissisticNum = 100; narcissisticNum < 1000; narcissisticNum++)
    {
        if (narcissisticNum == pow((narcissisticNum % 10), 3) + pow((narcissisticNum / 10 % 10), 3) + pow((narcissisticNum / 100 % 10), 3))
        {
            printf("%d\n", narcissisticNum);
        }
    }

    system("pause");
    return 0;
}
#include <stdio.h>

int isPerfectNum(int n)
{
    int s = 0;
    for (size_t i = 1; i < n; i++)
        if(n % i == 0)
            s += i;
    if(s == n)
        return 1;
    else
        return 0;
}
int main()
{
    int n;
	printf("Please enter the number to be judged:");
    scanf("%d",&n);
    if(isPerfectNum(n))
        printf("%d is perfect number\n",n);
    else
        printf("%d is not perfect numbern", n);
    return 0;
}
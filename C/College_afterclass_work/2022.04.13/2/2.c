#include <stdio.h>
#include <math.h>

int main(){
    float a, x0, x1;
    printf("Please enter a:");
    scanf("%f",&a);
    x1 = a / 2;
    do
    {
        x0 = x1;
        x1 = (x0 + a / x0) / 2;
    } while (fabs(x0 + a / x0) / 2);
    printf("The square root of %5.2f is %8.5f\n", a, x1);
    return 0;
}
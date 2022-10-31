#include <stdio.h>
#include <math.h>

int main(){
    void newtonSolution(float a, float b, float c, float d, float *x);
    float a, b, c, d;
    float x = 1;
    printf("Please enter var a,b,c,d:");
    scanf("%f%f%f%f", &a, &b, &c, &d);
    newtonSolution(a, b, c, d, &x);
    printf("x = %f", x);
    return 0;
}

void newtonSolution(float a, float b, float c, float d, float *x){
    float f, df, x0;
    do
    {
        x0 = *x;
        f  = (a * pow(x0, 3)) + (b * pow(x0, 2)) + c * x0 + d;
        df = (3 * a * pow(x0, 2)) + (2 * b * x0) + c;
        *x = x0 - f / df;
    } while (fabs(*x - x0) >= 1e-3);
}
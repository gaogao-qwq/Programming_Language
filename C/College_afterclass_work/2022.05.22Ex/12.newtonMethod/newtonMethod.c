#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x);
int roofx(double initRoot, double epsilon, double *root);

int main(){

    double root;
    int count;

    count = roofx(1, 1e-5, &root);    //初根，精度，引用调用根
    printf("Iterated %d times, the root is:%lf\n", count, root);

    return 0;
}

int roofx(double initRoot, double epsilon, double *root){

    double x0 = initRoot, x1 = 0;
    int iterativeCount = 0;

    do
    {
        printf("x%d=%lf\n", iterativeCount, x0);
        x1 = x0;
        x0 = f(x1);
        iterativeCount++;
    } while (fabs(x0 - x1) >= epsilon);
    *root = x0;

    return iterativeCount;
}

double f(double x){
    return (x - (pow(x, 3) + 2 * pow(x, 2) + 3 * x + 4) / (3 * pow(x, 2) + 4 * x + 3));
}
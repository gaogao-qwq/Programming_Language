#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int roofx();

    double a;
    double root;
    int count;

    printf("Please enter the val of var a:");
    scanf("%lf", &a);
    count = roofx(a, a / 2, 1e-5, &root);
    printf("Iterated %d times, the root is:%lf\n", count, root);

    return 0;
}

int roofx(double a, double initRoot, double epsilon, double *root){
    double f();

    double x0 = initRoot, x1 = 0;
    int iterativeCount = 0;

    do
    {
        printf("x%d=%lf\n", iterativeCount, x0);
        x1 = x0;
        x0 = f(x1, a);
        iterativeCount++;
    } while (fabs(x0 - x1) >= epsilon);
    *root = x0;

    return iterativeCount;
}

double f(double x, double a){
    return (0.5 * (x + a / x));
}
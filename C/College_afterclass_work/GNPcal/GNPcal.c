#include <stdio.h>
#include <math.h>

int main(){
    float r = 0.07;
    int n = 10;
    float p = pow((1 + r), n);
    printf("GNP increased by %lf compared to now", (p * 100));
    return 0;
}
#include <stdio.h>

int main(){

    int distance;
    float price, weight, discount, freight;

    printf("Please enter price:");
    scanf("%f", &price);
    printf("Please enter weight:");
    scanf("%f", &weight);
    printf("Please enter distance:");
    scanf("%d", &distance);

    if (distance >= 250 && distance < 500)
    {
        discount = 0.02;
    }
    if (distance >= 500 && distance < 1000)
    {
        discount = 0.05;
    }
    if (distance >= 500 && distance < 2000)
    {
        discount = 0.08;
    }
    if (distance >= 2000 && distance < 3000)
    {
        discount = 0.10;
    }
    else discount = 0.15;

    freight = price * weight * distance * (1 - discount);
    printf ("freight is:%f", freight);
    
    return 0;
}
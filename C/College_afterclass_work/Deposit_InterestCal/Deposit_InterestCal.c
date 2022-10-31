#include <stdio.h>
#include <math.h>

int main(){
    char choice = 1;
    float P;
    printf("1:5-year one-time deposit\n");
    printf("2:First deposit for 2 years, then deposit the current period for 3 years after maturity\n");
    printf("3:First deposit for 3 years, then deposit the current period for 2 years after maturity\n");
    printf("4:Deposit for one year, after maturity, deposit the principal and interest for another one year, deposit five times in a row\n");
    printf("5:Survival payment for 5 years\n");
    printf("Please enter your financial plan:");
    scanf("%c",&choice);
    switch (choice)
    {
    case '1':
        P = 1000 * (1 + 5 * 0.03);
        break;
    case '2':
        P = 1000 * (1 + 2 * 0.021) + 1000 * (1 + 3 * 0.0275);
        break;
    case '3':
        P = 1000 * (1 + 3 * 0.021) + 1000 * (1 + 2 * 0.0275);
        break;
    case '4':
        P = 1000 * pow((1 + 0.015), 5);
        break;
    case '5':
        P = 1000 * pow((1 + 0.0035/4), 5 * 4);
        break;
    default:
        printf("Invalid Num\n");
        break;
    }
    printf("The sum of your principal and interest is:%f", P);
}
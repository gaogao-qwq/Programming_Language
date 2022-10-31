#include <stdio.h>

int main(){
    void profitCalIf(float input_Float);
    void profitCalSwitch(float input_Float);

    float profit;
    int choice;

    printf("Please enter the profit:");
    scanf("%f", &profit);

    printf("[1]If()Mode  [2]Switch()Mode\n");
    printf("Please choose the mode you wanna use:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        profitCalIf(profit);
        break;
    case 2:
        profitCalSwitch(profit);
        break;
    default:
        printf("Invalid number!");
        break;
    }

    return 0;
}

void profitCalIf(float input_Float){
    float bonus = 0;

    if (input_Float >= 0 && input_Float <= 100000)
    {
        bonus = input_Float * 0.1;
    }
    else if (input_Float > 100000 && input_Float <= 200000)
    {
        bonus = 100000 * 0.1 + (input_Float - 100000) * 0.075;
    }
    else if (input_Float > 200000 && input_Float <= 400000)
    {
        bonus = 200000 * 0.1 + (input_Float - 200000) * 0.05;
    }
    else if (input_Float > 400000 && input_Float <= 600000)
    {
        bonus = 400000 * 0.1 + (input_Float - 400000) * 0.03;
    }
    else if (input_Float > 600000 && input_Float <= 1000000)
    {
        bonus = 600000 * 0.1 + (input_Float - 600000) * 0.015;
    }
    else if (input_Float > 1000000)
    {
        bonus = 1000000 * 0.1 + (input_Float - 1000000) * 0.01;
    }else
        printf("Invalid profit!");

    printf("The bonus is:%f", bonus);
}

void profitCalSwitch(float input_Float){
    int quotient = input_Float / 100000;
    float bonus = 0;

    if (input_Float >= 0)
    {
        switch (quotient)
        {
        case 0:
            bonus = 100000 * 0.1;
            break;
        case 1:
            bonus = 100000 * 0.1 + (input_Float - 100000) * 0.075;
            break;
        case 2:
        case 3:
            bonus = 200000 * 0.1 + (input_Float - 200000) * 0.05;
            break;
        case 4:
        case 5:
            bonus = 400000 * 0.1 + (input_Float - 400000) * 0.03;
            break;
        default:
            bonus = 1000000 * 0.1 + (input_Float - 1000000) * 0.01;
            break;
        }
        printf("The bonus is:%f", bonus);
    }else
        printf("Invalid profit!");
}
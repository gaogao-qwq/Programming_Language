#include <stdio.h>
#include <stdlib.h>

int main(){
    int score;

    void switchMode();

    do
    {
        printf("Please enter a score between 0 and 100:");
        scanf("%d", &score);
    } while (score < 0 || score > 100);

    switchMode(score);

    printf("\n");
    system("pause");
    return 0;
}

void scoreConverterSwitch(int input_Int){
    input_Int /= 10;

    switch (input_Int)
    {
    case 10:
    case 9:
        printf("your level is A");
        break;
    case 8:
        printf("your level is B");
        break;
    case 7:
        printf("your level is C");
        break;
    case 6:
        printf("your level is D");
        break;    
    default:
        printf("your level is E");
        break;
    }

}

void scoreConverterIf(int input_Int){

    if (input_Int >= 90)
        printf("your level is A");
    else if (input_Int >= 80 && input_Int < 90)
        printf("your level is B");
    else if (input_Int >= 70 && input_Int < 80)
        printf("your level is C");
    else if (input_Int >= 60 && input_Int < 70)
        printf("your level is D");
    else
        printf("your level is E");

}

void switchMode(int score)
{
    void scoreConverterSwitch();
    void scoreConverterIf();
    
    int choice;
    
    printf("[1]if mode  [2]switch mode\n");
    printf("Enter the mode you wanna choose:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        scoreConverterIf(score);
        break;
    case 2:
        scoreConverterSwitch(score);
        break;
    default:
        printf("Invaild number");
        break;
    }

}
#include <stdio.h>

int main(){
    int score;
    int choice;

    int scoreConverterSwitch();
    int scoreConverterIf();

    printf("Please enter a score between 0 and 100:");
    scanf("%d", &score);
    if (score > 0 && score < 101)
    {
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
    else printf("The score must between 0 and 100");
    
    return 0;
}

int scoreConverterSwitch(int input_Int){
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

    return 0;
}

int scoreConverterIf(int input_Int){

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

    return 0;
}
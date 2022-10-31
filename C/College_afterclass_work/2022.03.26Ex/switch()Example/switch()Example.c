#include <stdio.h>

int main(){
    int score;
    int scoreConverter();

    printf("Please enter a score between 0 and 100:");
    scanf("%d", &score);
    if (score > 0 && score < 101)
    {
        scoreConverter(score);
    }
    else printf("The score must between 0 and 100");
    
    return 0;
}

int scoreConverter(int input_Int){
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
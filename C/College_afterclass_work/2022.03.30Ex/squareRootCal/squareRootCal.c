#include <stdio.h>
#include <math.h>

int main(){
    int input_Int;
    int output_Int;
    int sqrtCal();

    printf("Please enter an Integer number between 0 and 1000:");
    scanf("%d", &input_Int);

    while (input_Int > 1000 && input_Int < 0){
    printf("Please enter an Integer number between 0 and 1000:");
    scanf("%d", &input_Int);
    }

    output_Int = sqrtCal(input_Int);
    printf("The square root is:%d", output_Int);
    
    return 0;
}

int sqrtCal(int input_Int){
    return (int)sqrt(input_Int);
}
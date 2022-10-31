#include <stdio.h>

int main(){
    int input_Int;
    float output_Float;
    float funcCal();

    printf("Please enter var x:");
    scanf("%d", &input_Int);

    output_Float = funcCal(input_Int);

    printf("y=%f", output_Float);
}

float funcCal(int input_Int){
    float ret;

    if(input_Int < 1)                    ret = input_Int;
    if(input_Int >= 1 || input_Int < 10) ret = (2 * input_Int -1);
    if(input_Int >= 10)                  ret = (3 * input_Int -3);

    return (ret);
}
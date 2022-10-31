#include <stdio.h>

int main(){
    int input_Int;

    void digitCal();
    void digitPrint();
    void digitReversePrint();

    printf("Please enter a number between 0 and 99999:");
    scanf("%u", &input_Int);

    if(input_Int >= 0 && input_Int < 100000)
    {
        digitCal(input_Int);
        digitPrint(input_Int);
        digitReversePrint(input_Int);
    }else
        {printf("Invalid number");}

    return 0;
}

void digitCal(int input_Int){
    int count = 0;

    if (input_Int != 0)
    {
        while (input_Int >= 1)
        {
            input_Int /= 10;
            count++;
        }
    }else
        count = 1;

    printf("The number has %d digits\n", count);
}

void digitPrint(int input_Int){
    int digits[5];
    int count = 0;
    
    if (input_Int != 0)
    {
        while (input_Int >= 1)
        {
            digits[count] = input_Int % 10;
            input_Int /= 10;
            count++;
        }

        for (int i = 1; count-- > 0;)
        {
            printf("The number of %dth digit is:%d\n", i++, digits[count]);
        }
    }else
        printf("The number of 1th digit is:0");
}

    void digitReversePrint(int input_Int){
        char str[5];
        sprintf(str, "%d", input_Int);
        printf("The reverse result is:");

        for (int i = 5; i >= 0; i--)
        {
            printf("%c", str[i]);
        }
    }

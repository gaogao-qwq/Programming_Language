#include <stdio.h>

int main(){
    
    char str[5];
    int encrypt[5];     //These arrays' size must bigger than the size of string user wanna input. 

    printf("Please enter a string of characters you wanna encrypt:");
    gets(str);

    for (int i = 0; i < 5; i++)
    {
        encrypt[i] = (int)str[i];
        encrypt[i] += 4;
        str[i] = (char)encrypt[i];
    }
    
    printf("(printf)The encrypted string is:%s\n",str);
    
    printf("(putchar)The encrypted string is:");
    for (int i = 0; i < 5; i++)
    {
        putchar(str[i]);
    }
    
    return 0;
}
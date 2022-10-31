#include <stdio.h>
#include <string.h>

void reverse(char str[]);
char str[10];

int main(){
    printf("Please enter a string:");
    scanf("%s", str);
    reverse(str);
    printf("The reverse string is:%s", str);
    return 0;
}

void reverse(char str[]){
    char temp;
    int len = strlen(str);
    for (int left = 0, right = len; left < len / 2; left++, right--)
    {
        temp = str[left];
        str[left] = str[right - 1];
        str[right - 1] = temp;
    }
}
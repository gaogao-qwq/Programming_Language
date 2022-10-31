#include <string.h>
#include <stdio.h>

void insert(char str[]);
char str[100];

int main(){
    printf("Please enter a string:");
    scanf("%s", str);
    printf("The original string is:%s", str);
    insert(str);
    printf("\nNow the string is:%s", str);
    return 0;
}

void insert(char str[]){
    int len = strlen(str);
    for (; len > 0; len--)
    {
        str[len * 2] = str[len];
        str[len * 2 - 1] = ' ';
    }
}

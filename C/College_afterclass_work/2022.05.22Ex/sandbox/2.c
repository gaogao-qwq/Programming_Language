#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool main(){
    int x = 1234567899;
    if(x < 0 || (x % 10 == 0 && x != 0))
    {
        return false;
    }
    char str[10];
    sprintf(str, "%d", x); //整型数每一位数转ASCII码存入字符串
    int size = strlen(str);
    for(int i = 0, j = size - 1; i < size / 2 ; i++, j--)
    {
        if(str[i] != str[j])
        {
            return false;
        }
    }
    return true;
}
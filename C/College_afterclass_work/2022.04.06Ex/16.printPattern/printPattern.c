#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[] = "       ";

    int i, j = 0;
    for (i = (strlen(str) / 2), j = (strlen(str) / 2); i >= 0 && j <= strlen(str); i--, j++)
    {
        str[i] = '*';
        str[j] = '*';
        printf("%s\n",str);
    }
    for (i = 0, j = (strlen(str) - 1); i < (strlen(str) / 2) && j >= (strlen(str) / 2); i++, j--)
    {
        str[i] = ' ';
        str[j] = ' ';
        printf("%s\n",str);
    }

    system("pause");
    return 0;
}
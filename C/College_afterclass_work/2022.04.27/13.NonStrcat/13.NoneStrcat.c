#include <stdio.h>
#include <string.h>

int main(){
    char str1[10], str2[10];
    int len1, len2;

    strcpy(str1, "Hello");
    strcpy(str2, "World");
    len1 = strlen(str1);
    len2 = strlen(str2);

    for (int i = 0; i < len2; i++)
    {
        str1[len1 + i] = str2[i];
    }
    puts(str1);
    
    return 0;
}
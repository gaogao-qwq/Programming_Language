#include <stdio.h>
#include <string.h>

int main(){
    char s1[50], s2[50];
    gets(s1);
    gets(s2);
    int len1 = strlen(s1), len2 = strlen(s2);
    for (size_t i = 0; i < len1 || i < len2; i++)
    {
        while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
        {
            /* code */
        }
        
    }
    

    return 0;
}
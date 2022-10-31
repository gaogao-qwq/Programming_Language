#include <stdio.h>

int main() 
{
    int sec;
    printf("Input sec:");
    scanf("%lu",&sec);
    printf("%lusec equals %luhours%lumins%lusecs",sec,sec/(60*60),sec%(60*60)/60,sec%60);
    getchar();
    getchar();
    return 0;
}
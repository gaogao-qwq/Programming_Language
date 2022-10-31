#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void bubbleSort(char str[], int len);
void swap(char *x, char *y);

int main () {
    char str[255];
    printf("Please enter a string:");
    scanf("%s", str);
    int len = strlen(str);
	
	bubbleSort (str, len);
    printf("%s", str);

    return 0;
}

void bubbleSort (char str[], int len){
	int temp;
	_Bool isExchanged = true;

    for (int i = 0; isExchanged && i < len - 1; i++)
    {
        isExchanged = false;
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (str[j] > str[j + 1])
            {
                swap(&str[j], &str[j + 1]);
                isExchanged = true;
            }
        }
    }
}

//交换函数
void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}
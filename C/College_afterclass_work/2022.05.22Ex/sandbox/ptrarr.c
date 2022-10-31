#include <stdio.h>

int main(){
    char* array[] = {"hello", "world", "!"};
    *(&array[0]) = "well";
    printf("%s", array[0]);
    return 0;
}
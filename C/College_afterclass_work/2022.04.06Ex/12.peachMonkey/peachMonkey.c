#include <stdio.h>
#include <stdlib.h>

int main(){
    int peach = 1;

    for (size_t i = 0; i < 10; i++)
    {
        peach = (peach + 1) * 2;
    }
    printf("%d", peach);

    system("pause");
    return 0;
}
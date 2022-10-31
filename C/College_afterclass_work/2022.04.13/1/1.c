#include <stdio.h>

int main(){
    int f1 = 1, f2 = 1, f3;
    printf("%12d\n%12d\n", f1, f2);
    size_t count = 0;
    for (size_t i = 0; i < 38; i++)
    {
        f3 = f1 + f2;
        if (count < 5)
        {
            printf("%12d",f3);
            count++;
        }else
        {
            printf("%12d\n",f3);
        }
        f1 = f2;
        f2 = f3;
    }
    return 0;
}
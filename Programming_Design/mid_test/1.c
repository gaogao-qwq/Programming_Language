#include <stdio.h>

int main(int argc, char **argv) {
    int sum = 0;
    for (int i = 1; i <= 100; ++i) {
        sum += !(i % 3) || !(i % 5) ? i : 0;
    }
    printf("%d", sum);
    return 0;
}
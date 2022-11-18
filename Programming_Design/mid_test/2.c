#include <stdio.h>

// fib 典中典，经典 dp 入门题，空间压缩后空间复杂度 O(1)
int main(int argc, char **argv) {
    int prev = 1, curr = 1;
    printf("%d %d ", prev, curr);
    for (int i = 2; i < 20; ++i) {
        int tmp = curr;
        curr = prev + curr, prev = tmp;
        printf("%d ", curr);
    }
    return 0;
}
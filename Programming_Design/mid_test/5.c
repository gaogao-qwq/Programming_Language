#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multip(int a, int b) {
    return a * b;
}

int division(int a, int b) {
    return a / b;
}

int main(int argc, char **argv) {
    int a = 114, b = 514;
    printf("a + b = %d, a - b = %d, a * b = %d, a / b = %d", add(a, b), subtract(a, b), multip(a, b), division(a, b));
    return 0;
}
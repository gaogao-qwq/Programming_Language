#include <bits/stdc++.h>
using namespace std;

void my_swap(int *a, int *b) {
    *a ^= *b ^= *a ^= *b;
}

int main() {
    int a(0), b(0);
    cin >> a >> b;
    if ((a - b) >> 31) {
        my_swap(&a, &b);
    }
    cout << a << " " << b;
    return 0;
}
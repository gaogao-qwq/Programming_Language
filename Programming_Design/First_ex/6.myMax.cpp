#include <bits/stdc++.h>
using namespace std;

int main() {
    int num1(0), num2(0);
    cin >> num1 >> num2;
    // 匿名函数也是函数
    cout << [](int a, int b){return a > b ? a : b;}(num1, num2);
    return 0;
}
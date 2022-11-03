#include <bits/stdc++.h>
using namespace std;

int main() {
    double num1(0.0), num2(0.0);
    cin >> num1 >> num2;
    auto add = [](double a, double b){return a + b;};
    cout << add(num1, num2);
    return 0;
}
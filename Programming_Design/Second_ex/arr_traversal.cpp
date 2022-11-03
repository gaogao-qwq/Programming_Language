#include <bits/stdc++.h>
using namespace std;

int main() {
    // C:
    // 遍历法1：
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // 遍历法2：
    auto p = arr;
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
        cout << *(p + i) << " ";
    }
    cout << endl;
    // 遍历法3：
    p = arr;
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i, ++p) {
        cout << *p << " ";
    }
    cout << endl;

    // C++:
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // 传统
    for(int i = 0; i < vec.size(); ++i) cout << vec[i] << " ";
    cout << endl;
    // 语法糖
    for(auto i : vec) cout << i << " ";
    cout << endl;
    // 迭代器
    for(auto i = vec.begin(); i != vec.end(); ++i) cout << *i << " ";

    return 0;
}
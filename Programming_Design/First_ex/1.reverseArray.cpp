#include <bits/stdc++.h>
using namespace std;

//实现2：手撕库函数（准确的来说是手撕模板）
void reverseIntegerArr(vector<int>::iterator first, vector<int>::iterator last) {
    while ( (first != last) && (first != --last) ) {
        iter_swap(first, last);
        ++first;
    }
}

int main() {
    vector<int> arr{8,6,5,4,1};

    // 实现1：调库
    reverse(arr.begin(), arr.end());
    for(auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    reverseIntegerArr(arr.begin(), arr.end());
    for(auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
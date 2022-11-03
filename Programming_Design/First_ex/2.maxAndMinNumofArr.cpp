#include <bits/stdc++.h>
using namespace std;

// 实现2：手撕
vector<int>::iterator maxElementofIntegerArr(vector<int>::iterator first, vector<int>::iterator last) {
    if (first == last) return first;
    auto res = first;
    while (++first != last) {
        res = *first > *res ? first : res;
    }
    return res;
}

vector<int>::iterator minElementofIntegerArr(vector<int>::iterator first, vector<int>::iterator last) {
    if (first == last) return first;
    auto res = first;
    while (++first != last) {
        res = *first < *res ? first : res;
    }
    return res;
}

int main() {
    vector<int> arr{1,1,4,5,1,4,1,9,1,9,8,1,0};

    // 实现1：调库
    cout << "max:" << *max_element(arr.begin(), arr.end()) << endl 
         << "min:" << *min_element(arr.begin(), arr.end()) << endl;

    cout << "max:" << *maxElementofIntegerArr(arr.begin(), arr.end()) << endl
         << "min:" << *minElementofIntegerArr(arr.begin(), arr.end()) << endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// 数据少 插排 稳定 最坏O(n2) 几乎有序时O(n)
void insertion_sort(vector<int> &arr, int n) {
    int insert_elem = 0;
    int position = 0;
    int i = 0;
    for (i = 1; i < n; ++i) {
        insert_elem = arr[i];
        position = i;
        while (position > 0 && arr[position - 1] < insert_elem) {
            arr[position] = arr[position - 1];
            position--;
        }
        if (position != i) {
            arr[position] = insert_elem;
        }
    }
}

int main() {
    vector<int> arr(3, 0);
    for (auto &i : arr) {
        cin >> i;
    }
    insertion_sort(arr, arr.size());
    for (auto i : arr) {
        cout << i << " ";
    }
    return 0;
}
/* 同洛谷P1046 [NOIP2005 普及组] https://www.luogu.com.cn/problem/P1046 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> apples(10);
    int height = 0, cnt = 0;
    for(int i = 0; i < 10; ++i) {
        cin >> apples[i];
    }
    cin >> height;
    height += 30;
    for(auto i : apples) {
        cnt += height >= i;
    }
    cout << cnt;
    return 0;
}
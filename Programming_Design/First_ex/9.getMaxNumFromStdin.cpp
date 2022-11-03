#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans(0), nth(0);
    for(int i = 0, tmp = 0; i < 10; ++i) {
        cin >> tmp;
        if(tmp > ans) {
            ans = tmp;
            nth = i + 1;
        }
    }
    cout << "第" << nth << "个数为最大值，值为：" << ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> mat{{1,1,4,5},{1,4,1,9},{1,9,8,1}};
    int ans(0), row(0), col(0);
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 4; ++j) {
            if(mat[i][j] > ans) {
                ans = mat[i][j], row = i + 1, col = j + 1;
            }
        }
    }
    cout << "第" << row << "行第" << col << "列有最大值" << ans << endl;
    return 0;
}
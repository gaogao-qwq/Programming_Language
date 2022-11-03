/* 同OpenJudge ch0108-01 http://noi.openjudge.cn/ch0108/01/ */
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> mat(5, vector<int>(5));
    int m(0), n(0);
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            cin >> mat[i][j];
        }
    }
    cin >> m >> n;
    for(int i = 0; i < 5; ++i) {
        swap(mat[m - 1][i], mat[n - 1][i]);
    }
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
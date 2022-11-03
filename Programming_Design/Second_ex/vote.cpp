#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, int> candidate{{"Pixy", 0}, {"Trigger", 0}, {"Mobius", 0}};
    int n(0);
    cout << "输入选民数量：";
    cin >> n;
    for(int i = 0; i < n; ++i) {
        string s;
        cout << "选民" << i + 1 << " 请输入你的选择：";
        cin >> s;
        if(candidate.find(s) != candidate.end()) {
            ++candidate[s];
            continue;
        }
        cout << "没有这个候选人" << endl;
        --i;
    }
    for(auto i : candidate) {
        cout << "候选人：" << i.first << "  得票：" << i.second << endl;
    }
    return 0;
}
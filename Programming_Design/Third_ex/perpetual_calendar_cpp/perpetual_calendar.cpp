#include <bits/stdc++.h>
using namespace std;

// 格里高利闰年规则：
// 公元年分非4的倍数，为平年。
// 公元年分为4的倍数但非100的倍数，为闰年。
// 公元年分为100的倍数但非400的倍数，为平年。
// 公元年分为400的倍数为闰年。

// 难点之一为要计算所求年分第一天为星期几
// 难点之二为教皇格里戈八世在1582年2月24日颁布法令，永远抹去了1582年10月5日到1582年10月14日。
// 换句话说，如果我们这样向前推算，公元1年1月1日应当为周六而非周一

// 首先将问题先转化为求 1年1月1日 至 所求年1月1日 间的总天数 w
// 我知道你很想用 if else 嵌套，但实际上用数学的思路，一个公式足矣
// w = 365 * y + y / 4 - y / 100 + y / 400
// 接着对求得的 w 取模 7 即可得知这一天是星期几

// 或者如果你是OI人，也可以直接用蔡勒公式
// 下面的 compute_date() 实际上用的就是蔡勒公式的思想

// 造俩数组当 map 使
vector<int> months{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> months_leap{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int compute_date(int y, int m, int d) {
    if (m < 3) --y, m += 12;
    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306;
}

vector<vector<int>> generate_calendar(int y) {
    int n = 365;
    vector<int> date = months;
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        ++n, date = months_leap;
    }

    vector<vector<int>> calendar(n, vector<int>(3));
    int m = 1, d = 1;
    for (int i = 0; i < n; ++i) {
        calendar[i][0] = m, calendar[i][1] = d, calendar[i][2] = compute_date(y, m, d) % 7;
        if (++d > date[m - 1]) {
            ++m, d = 1;
        }
    }
    return calendar;
}

void print_calendar(vector<vector<int>> calendar, int y) {
    int n = 365;
    vector<int> date = months;
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        ++n, date = months_leap;
    }

    int d = 0, m = 0;
    for (int i = 0; i < calendar.size(); ++i) {
        if (m != calendar[i][0]) {
            d = 0, ++m;
            cout << "\n\n\n" << setw(11) << calendar[i][0] << "月" << endl
                             << setw(3) << "Su"
                             << setw(3) << "Mo"
                             << setw(3) << "Tu"
                             << setw(3) << "We"
                             << setw(3) << "Th"
                             << setw(3) << "Fr"
                             << setw(3) << "Sa" << endl;
        }
        while(d != calendar[i][2]) {
            cout << "   ";
            ++d;
        }
        cout << setw(3) << calendar[i][1];
        ++d;
        if (d > 6) {
            cout << "\n";
            d = 0;
        }
    }
}

int main() {
    // 取消同步以提高读速
    ios_base::sync_with_stdio(false);
    while (true) {
        int year = 1;
        cout << "\n请输入年份（Ctrl-C 退出）：";
        cin >> year;
        if (year < 1) {
            cerr << "输入非法！\n";
            continue;
        }
        print_calendar(generate_calendar(year), year);
    }
    return 0;
}
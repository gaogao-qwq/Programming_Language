#include <bits/stdc++.h>
using namespace std;

// 造俩数组当 map 使
const vector<int> months{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const vector<int> months_leap{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 24个参数实现 O(1) 复杂度用于计算 1582年 10月 15日前的年份
inline int compute_old_date(int y, int m, int d) {
    // 这里需要注意一点，由于 1582 年格里高利历实行前是不存在“能被100整除且不能被400整除的年份是闰年”这种规定的
    int yd = 365 * (y - 1) + (y - 1) / 4 + 5;

    // 这里需要注意一点，由于 1582 年格里高利历实行前是不存在“能被100整除且不能被400整除的年份是闰年”这种规定的
    // if isLeap:
    if (y % 4 == 0)
        return (yd + accumulate(months_leap.begin(), months_leap.begin() + m - 1, 0) + d) % 7;

    return (yd + accumulate(months.begin(), months.begin() + m - 1, 0) + d) % 7;
}

// 蔡勒公式改编实现 O(1) 时间复杂度
inline int compute_date(int y, int m, int d) {
    if (m < 3) --y, m += 12;
    return (365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306) % 7;
}

// calendar 数组生成函数
vector<vector<int>> generate_calendar(int y) {
    int n = 365;
    // 做浅拷贝足矣，但反正也只用一行，深拷贝就深拷贝吧
    vector<int> date = months;
    // if isLeap:
    // 这里需要注意一点，由于 1582 年格里高利历实行前是不存在“能被100整除且不能被400整除的年份是闰年”这种规定的
    if (((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) || (y < 1582 && y % 4 == 0))
        ++n, date = months_leap;

    // 初始化 calendar 数组
    vector<vector<int>> calendar(n, vector<int>(3));
    // 生成 calendar 数组
    int m = 1, d = 1;
    for (int i = 0; i < n; ++i) {
        // 1582年前用 compute_old_date
        if (y < 1582)
            calendar[i][0] = m, calendar[i][1] = d, calendar[i][2] = compute_old_date(y, m, d);
        // 1582年后用蔡勒公式
        if (y > 1582)
            calendar[i][0] = m, calendar[i][1] = d, calendar[i][2] = compute_date(y, m, d);
        // 1582年比较特殊，写个特判
        if (y == 1582) {
            if (m < 10) calendar[i][0] = m, calendar[i][1] = d, calendar[i][2] = compute_old_date(y, m, d);
            if (m == 10) {
                if (d < 15) calendar[i][0] = m, calendar[i][1] = d, calendar[i][2] = compute_old_date(y, m, d);
                else calendar[i][0] = m, calendar[i][1] = d, calendar[i][2] = compute_date(y, m, d);
            }
            if (m > 10) calendar[i][0] = m, calendar[i][1] = d, calendar[i][2] = compute_date(y, m, d);
        }
        if (++d > date[m - 1]) ++m, d = 1;
    }
    return calendar;
}

// 打印日历函数
void print_calendar(vector<vector<int>> calendar, int y) {
    int n = 365;
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ++n;

    int d = 0, m = 0;
    for (int i = 0; i < calendar.size(); ++i) {
        // 打印月及日历抬头指示
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
        // 补齐空格
        while (d != calendar[i][2]) {
            cout << "   ";
            ++d;
        }
        // 打印日
        if (y == 1582 && m == 10 && calendar[i][1] == 5) i += 10;
        cout << setw(3) << calendar[i][1];
        ++d;
        // 每七天换行
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
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

// 造俩数组当 map 使
const int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int months_leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int accumulate(const int *arr, int begin, int end) {
    int sum = 0;
    for (int i = begin; i < end; ++i) sum += arr[i];
    return sum;
}

// 24个参数实现 O(1) 复杂度用于计算 1582年 10月 15日前的年份
inline int compute_old_date(int y, int m, int d) {
    // 这里需要注意一点，由于 1582 年格里高利历实行前是不存在“能被100整除且不能被400整除的年份是闰年”这种规定的
    int yd = 365 * (y - 1) + (y - 1) / 4 + 5;
    // if isLeap:
    if (y % 4 == 0)
        return (yd + accumulate(months_leap, 0, m - 1) + d) % 7;

    return (yd + accumulate(months, 0, m - 1) + d) % 7;
}

inline int compute_date(int y, int m, int d) {
    // 蔡勒公式改编实现 O(1) 时间复杂度查找到任意年任意月任意天是周几
    if (m < 3) --y, m += 12;
    return (365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 + d - 306) % 7;
}

int **generate_calendar(int y) {
    int n = 365;
    // 做个浅拷贝足矣
    const int *date = months;
    // 这里需要注意一点，由于 1582 年格里高利历实行前是不存在“能被100整除且不能被400整除的年份是闰年”这种规定的
    if (((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) || (y < 1582 && y % 4 == 0))
        ++n, date = months_leap;

    // 初始化 calendar 数组
    // 现在知道为什么 C 在现代适合且只适合写内核了吧。
    int **calendar = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i)
        calendar[i] = (int *)malloc(3 * sizeof(int));

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

void print_calendar(int **calendar, int y) {
    int n = 365;
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ++n;

    int d = 0, m = 0;
    for (int i = 0; i < n; ++i) {
        // 打印月及日历抬头指示
        if (m != calendar[i][0]) {
            d = 0, ++m;
            printf("\n\n\n");
            printf("%11d月\n", calendar[i][0]);
            printf(" Su Mo Tu We Th Fr Sa\n");
        }
        // 补齐空格
        while (d != calendar[i][2]) {
            printf("   ");
            ++d;
        }
        // 打印日
        if (y == 1582 && m == 10 && calendar[i][1] == 5) i += 10;
        printf("%3d", calendar[i][1]);
        ++d;
        // 换行
        if (d > 6) {
            printf("\n");
            d = 0;
        }
    }
}

int main() {
    while (true) {
        int year = 1;
        printf("\n请输入年份（Ctrl-C 退出）：");
        scanf("%d", &year);
        if (year < 1) {
            printf("输入非法！\n");
            continue;
        }
        print_calendar(generate_calendar(year), year);
    }
    return 0;
}
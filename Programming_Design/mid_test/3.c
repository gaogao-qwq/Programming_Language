#include <stdio.h>

int main(int argc, char **argv) {
    int score[10] = {110, 45, 56, 140, 80, 70, 81, 0, 95, 86};
    int sum = 0, cnt = 0;
    for (int i = 0; i < 10; ++i) {
        sum += score[i];
    }
    double aver = sum / 10.0;
    for (int i = 0; i < 10; ++i) {
        if (score[i] > aver) ++cnt;
    }
    printf("平均成绩：%.2f，高于平均成绩的学生人数：%d", aver, cnt);
    return 0;
}
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct student{
    int no;
    char name;
    int class_no;
    int score;
}STU;

STU stu[3];

int cmp(const void *a, const void *b) {
    STU *p1 = (STU *)a;
    STU *p2 = (STU *)b;
    return (p1->score) < (p2->score) ? 1 : -1;
}

int main(int argc, char **argv) {
    stu[0].no = 1, stu[0].name = 'A', stu[0].class_no = 1, stu[0].score = 81;
    stu[1].no = 2, stu[1].name = 'B', stu[1].class_no = 1, stu[1].score = 60;
    stu[2].no = 1, stu[2].name = 'C', stu[2].class_no = 2, stu[2].score = 70;
    qsort(stu, 3, sizeof(STU), cmp);
    for (int i = 0; i < 3; ++i) {
        printf("姓名：%c 学号：%d 班级：%d 分数：%d\n", stu[i].name, stu[i].no, stu[i].class_no, stu[i].score);
    }
    return 0;
}
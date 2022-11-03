#include <bits/stdc++.h>
using namespace std;

class student {
public:
    string id;
    string name;
    float score;
public:
    // 构造函数
    student() : id(""), name(""), score(0.0) {}
    student(string id) : id(id), name(""), score(0.0) {}
    student(string id, string name) : id(id), name(name), score(0.0) {}
    student(string id, string name, float score) : id(id), name(name), score(score) {}
};

int main() {
    auto stu1 = new student("田所浩二", "114514", 64), stu2 = new student("朴秀", "1919", 99);
    auto ans = (stu1->score > stu2->score) ? stu1 : stu2;
    cout << ans->id << endl << ans->name << endl << ans->score;
    return 0;
}
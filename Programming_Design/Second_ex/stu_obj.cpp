#include <bits/stdc++.h>
using namespace std;

class student {
public:
    string id;
    string name;
    string sex;
    string addr;
public:
    student(string id) : id(id), name(""), sex(""), addr("") {}
    student(string id, string name) : id(id), name(name), sex(""), addr("") {}
    student(string id, string name, string sex) : id(id), name(name), sex(sex), addr("") {}
    student(string id, string name, string sex, string addr) : id(id), name(name), sex(sex), addr(addr) {}
};

int main() {
    auto stu = new student("114514", "田所浩二", "男", "下北泽");
    cout << stu->id << endl << stu->name << endl << stu->sex << endl << stu->addr;
    return 0;
}
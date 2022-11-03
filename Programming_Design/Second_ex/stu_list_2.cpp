#include <bits/stdc++.h>
using namespace std;

class StuListNode {
private:
    string id;
    string name;
    float score;
    StuListNode *next;
public:
    // 构造函数
    StuListNode() : id(""), name(""), score(0.0), next(nullptr) {}
    StuListNode(string id) : id(id), name(""), score(0.0), next(nullptr) {}
    StuListNode(string id, string name) : id(id), name(name), score(0.0), next(nullptr) {}
    StuListNode(string id, string name, float score) : id(id), name(name), score(score), next(nullptr) {}
    StuListNode(string id, string name, float score, StuListNode *next) : id(id), name(name), score(score), next(next) {}
public:
    StuListNode* sortLists(StuListNode* head);
    void printList(StuListNode *head);
};

// 归并排序
StuListNode *StuListNode::sortLists(StuListNode* head) {
    // 分割递归终止条件
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    // 定义并初始化快慢指针
    auto fast = head->next, slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        // 慢指针一次移动一个结点
        slow = slow->next;
        // 快指针一次移动两个结点
        fast = fast->next->next;
    }
    // 循环结束后快指针指向链表尾部 nullptr，慢指针指向链表中间结点的前驱结点。
    // 用 tmp 缓存中间结点，然后从中间分割链表。
    auto tmp = slow->next;
    slow->next = nullptr;
    auto left = sortLists(head);
    auto right = sortLists(tmp);

    // 合并递归
    auto h = new StuListNode();
    auto res = h;
    while (left != nullptr && right != nullptr) {
        if(left->score > right->score) {
            h->next = left;
            left = left->next;
        } else {
            h->next = right;
            right = right->next;
        }
        h = h->next;
    }
    h->next = (left != nullptr) ? left : right;
    return res->next;
}

// 打印链表
void StuListNode::printList(StuListNode *head) {
    auto p = head;
    while(p != nullptr) {
        cout << p->id    << endl
             << p->name  << endl
             << p->score << endl
                         << endl;
        p = p->next;
    }
}

int main() {
    // 懒得写用户输入实现了，硬编码得了
    auto head = new StuListNode("114514", "田所浩二", 80, new StuListNode("1919", "朴秀", 59, new StuListNode("810", "TNOK", 78)));
    head = head->sortLists(head);
    head->printList(head);
    return 0;
}
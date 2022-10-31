#include <iostream>
#include <vector>
#include <list>

using namespace std;
int main(int argc, char **argv) {
    vector<int> v{1,2,3,4,5,6,7,8,9,10};
    cout << "第一种遍历方法：" << endl;
    // 这里也可以用：
    // for (int i = 0; i < v.size(); ++i)
    for (int i : v) {
        cout << i << " "; // 像普通数组一样使用vector容器
    }

    cout << endl << "第二种遍历方法：" << endl;
    // 创建一个正向迭代器，当然，vector也支持其他 3 种定义迭代器的方式
    vector<int>::iterator i;
    for (i = v.begin(); i != v.end(); ++i) { // 用 != 比较两个迭代器
        cout << *i << " ";
    }

    cout << endl << "第三种遍历方法：" << endl;
    for (i = v.begin(); i < v.end() ; ++i) { // 用 < 比较两个迭代器
        cout << *i << " ";
    }

    cout << endl << "第四种遍历方法：" << endl;
    i = v.begin();
    while (i < v.end()) {
        cout << *i << " ";
        i += 2; // 随机访问迭代器支持 "+= 整数" 的操作
    }


    // 创建一个 l list容器
    list<int> l{1,2,3,4,5,6,7,8,9,10};
    // 创建一个常量正向迭代器，同样，list也支持其他三种定义迭代器的方式。
    list<int>::const_iterator j;
    cout << endl << "list 容器的迭代器是双向迭代器，以下代码合法：" << endl;
    for(j = l.begin(); j != l.end(); ++j) {
        cout << *j << " ";
    }

/**
 * 其实在 C++ 中，数组也是容器。数组的迭代器就是指针，而且是随机访问迭代器。例如，对于数组 int a[10]，int * 类型的指针就是其迭代器。
 */

    return 0;
}

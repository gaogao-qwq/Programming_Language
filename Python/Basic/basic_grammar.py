# -*- coding: UTF-8 -*-
# Python 源码文件以 UTF-8 编码，所有字符串都是 Unicode 字符串。

# Python 可以使用反斜杠符 \ 来实现多行语句
print("A very very very very very very \
very very very long sentence")

# Python 可以在同一行中使用多条语句，各语句间用 ; 来分隔
import sys; string = "Hello world!"; print(string)

# Python 中缩进相同的一组语句构成一个代码块，我们称之代码组。
for i in range(0, 2):
    for j in range(0, 2):
        print(i + j)

# Python print输出默认换行，想实现不换行输出需要加上 end = ""
x = "a"
y = "b"

print("换行输出")
print(x)
print(y)

print("不换行输出")
print(x, end=" ")
print(y, end="")

n = eval(input("输入一个n的值："))

for i in range(1, n + 1):
    print(" " * (n - i), end="")
    for j in range(i):
        print("*", end=" ")
    print(" " * (n - 1))

for i in range(n - 1, 0, -1):
    print(" " * (n - i), end="")
    for j in range(i):
        print("*", end=" ")
    print(" " * (n - 1))

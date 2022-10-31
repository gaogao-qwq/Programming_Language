num1 = 0
num2 = 1
count = 2
length = int(input("Please enter the length of the sequence:"))
if length <= 0:
    print("Please enter a positive integer.")
elif length == 1:
    print("Fibonacci sequence is:" + str(num1))
elif length == 2:
    print("Fibonacci sequence is:" + str(num1) + ", " + str(num2))
else:
    print("Fibonacci sequence is:" + str(num1) + ", " + str(num2), end=", ")
    while count < length:
        count += 1
        _sum = num1 + num2
        # 为了消除数列末尾的逗号，加上一个判断
        if count < length:
            print(_sum, end=", ")
        else:
            print(_sum, end="")
        # 打印完后进行变量移动
        num1 = num2; num2 = _sum


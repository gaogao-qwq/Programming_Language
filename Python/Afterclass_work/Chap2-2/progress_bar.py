import time
print("{:=^54}".format("下载开始"))
for i in range(101):
    left = i // 2; right = 100 // 2 - left
    print("\r" + str(i) + "%" + "[" + "*" * left + "." * right + "]", end="")
    time.sleep(0.01)
print("\n" + "{:=^54}".format("下载完成"))

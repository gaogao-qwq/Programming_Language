def solution1() -> None:
    for i in range(1, 10):
        for j in range(1, i + 1):
            print("{:<8}".format(str(i) + "*" + str(j) + "=" + str(i * j)), end="")
        print()


def solution2() -> None:
    i = 1
    while i < 10:
        j = 1
        while j <= i:
            print("{:<8}".format(str(i) + "*" + str(j) + "=" + str(i * j)), end="")
            j += 1
        print()
        i += 1


solution1()
print()
solution2()

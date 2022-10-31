from itertools import *

dic = {
    0: "+",
    1: "-",
    2: "*",
    3: "**",
    4: "//",
    5: "%",
    6: "|",
    7: "&",
    8: "^",
    9: "<<",
    10: ">>"
}


def check(status):
    for t in opts:
        if t not in status:
            return False
    return True


def bk(idx, res, status):
    if idx == 4:
        if res == 1024 and check(status):
            plan_out = '(('
            for i in range(4):
                tmp = ') ' if i not in (0, 3) else ' '
                plan_out += str(combin[i]) + tmp
                if i != 3:
                    plan_out += dic[status[i]] + ' '
            print(plan_out)
        return

    val = combin[idx]

    for i in range(11):
        if i == 0:
            bk(idx + 1, res + val, status + [0])
        elif i == 1:
            bk(idx + 1, res - val, status + [1])
        elif i == 2:
            bk(idx + 1, res * val, status + [2])
        elif i == 3:
            bk(idx + 1, res**val, status + [3])
        elif i == 4 and val != 0:
            bk(idx + 1, res // val, status + [4])
        elif i == 5 and val != 0:
            bk(idx + 1, res % val, status + [5])
        elif i == 6:
            bk(idx + 1, res | val, status + [6])
        elif i == 7:
            bk(idx + 1, res & val, status + [7])
        elif i == 8:
            bk(idx + 1, res ^ val, status + [8])
        elif i == 9:
            bk(idx + 1, res << val, status + [9])
        elif i == 10:
            bk(idx + 1, res >> val, status + [10])


if __name__ == '__main__':
    # 已经获得的 3 张数字牌
    ori = [2, 20, 30]
    # 已经获得的运算符
    opts = [7]

    for i in list(range(101)) + [955, 996, 1024, 1075, 1337]:
        nums = ori + [i]
        print('使用 %i 的' % i)
        for combin in permutations(nums):
            bk(1, combin[0], [])


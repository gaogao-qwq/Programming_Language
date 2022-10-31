from random import randrange

balance = 10000
i = 1
while balance > 0:
    performance = randrange(1, 11, 1)
    if performance < 5:
        print("员工{i}，绩效分{performance}，低于5，不发工资，下一位"
              .format(i=i, performance=performance))
        i += 1
    else:
        balance -= 1000
        print("向员工{i}发放工资1000元，账户余额还剩余{balance}元"
              .format(i=i, balance=balance))
        i += 1
    if i >= 20:
        i = 1

print("工资发完了，下个月领取吧")

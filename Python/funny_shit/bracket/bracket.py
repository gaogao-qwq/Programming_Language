from typing import Set
import operator as op
variables = {}


class MyCode:
    index = 0

    def __hash__(self):
        MyCode.index += 1
        return MyCode.index

    def do(self):
        ...


# 赋值类
class SetValue:
    def __init__(self, name, value):
        self.name = name
        self.value = value

    def do(self):
        variables[self.name] = self.value

    def __str__(self):
        return "<SetValue>"


# 访问变量值类
class GetValue(MyCode):
    def __init__(self, name):
        self.name = name

    def do(self):
        return variables[self.name]


# 赋值类
class ChangeValue:
    def __init__(self, name, delta_value, op):
        self.name = name
        self.delta_value = delta_value
        self.op = op

    def do(self):
        variables[self.name] = self.op(variables[self.name], self.delta_value)


# 二元运算符类
class Operator(MyCode):
    def __init__(self, lvalue, operator, rvalue):
        self.lvalue = lvalue
        self.operator = operator
        self.rvalue = rvalue

    def do(self):
        if isinstance(self.lvalue, str):
            return self.operator(variables[self.lvalue], self.rvalue)
        elif isinstance(self.lvalue, MyCode):
            return self.operator(self.lvalue.do(), self.rvalue)
        else:
            return self.operator(self.lvalue, self.rvalue)


# If 条件语句类
class If(MyCode):
    def __init__(self, *args, **kwargs):
        # if ((condition) {} else {})
        if len(args) == 4:
            self.condition = args[0]
            self.doCode: Set[MyCode] = args[1]
            self.elseDo: Set[MyCode] = args[3]
        # if((condition) {})
        elif len(args) == 2:
            self.condition = args[0]
            self.doCode: Set[MyCode] = args[1]
            self.elseDo: Set[MyCode] = set()

    def do(self):
        if self.condition.do():
            for code in self.doCode:
                code.do()
        elif self.elseDo:
            for code in self.elseDo:
                code.do()

    def __str__(self):
        return "<IF>"


# For 循环语句类
class For(MyCode):
    def __init__(self, init_content, judge_content, loop_content, loop_code):
        self.initContent = init_content
        self.judgeContent = judge_content
        self.loopContent = loop_content
        self.loopCode = loop_code

    def do(self):
        self.initContent.do()
        while self.judgeContent.do():
            for code in self.loopCode:
                code.do()
            self.loopContent.do()


# Print 类
class Print(MyCode):
    def __init__(self, string):
        self.string = string

    def do(self):
        if isinstance(self.string, str):
            print(self.string)
        elif isinstance(self.string, MyCode):
            print(self.string.do())


# namespace 类
class NameSpace:
    def __init__(self, *args):
        self.arr = args

    def run(self):
        for code in self.arr:
            code.do()


# 打印 0~1000 内的所有偶数
ns = NameSpace(
    For(SetValue("i", 0), Operator(GetValue("i"), op.lt, 1000), ChangeValue("i", 1, op.add), {
        # (i % 2) == 0
        If((Operator(Operator("i", op.mod, 2), op.eq, 0)), {
            Print(GetValue("i"))
        })
    })
)


def main():
    ns.run()
    print(variables)


if __name__ == '__main__':
    main()

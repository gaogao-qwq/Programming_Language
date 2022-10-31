# 函数定义支持可变数量的参数。这里列出三种可以组合使用的形式。

# 默认值参数
# 为参数指定默认值是非常有用的方式。调用函数时，可以使用比定义时更少的参数，例如：
def ask_ok(prompt, retries=4, reminder='Please try again!'):
    while True:
        ok = input(prompt)
        if ok in ('y', 'ye', 'yes'):
            return True
        if ok in ('n', 'no', 'nop', 'nope'):
            return False
        retries = retries - 1
        if retries < 0:
            raise ValueError('invalid user response')
        print(reminder)



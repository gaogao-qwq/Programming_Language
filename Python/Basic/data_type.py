# Python 中有六个基础数据类型：Number, String, List, Tuple, Set, Dictionary
# Python 中的数据类型可分为不可变数据与可变数据，不可变数据即更改变量值后该变量地址会变化，可变数据即更改变量值后该变量地址不变化。
# Python 中可使用 id() 方法得到变量地址
# 不可变数据：Number（数字），String（字符串），Tuple（元组）
# 可变数据：List（列表），Dictionary（字典），Set（集合）

# Number:
_int = 1
_float = 1.0
_bool = True
_complex = 1j

# String:
_str = "Hello"

# List
_list = ["Hello", "World", 114514]

# Tuple
_tuple = ("this", "is", "a", "tuple")

# Set
_set = {"this", "is", "a", "set"}

_set_1 = {"Hello", "World"}
_set_2 = {"Hello", "Python"}

print(_set_1 - _set_2)          # 打印差集
print(_set_1 & _set_2)          # 打印交集

# Dictionary
_dict = {"id": 114514, "name": "田所浩二"}
print(_dict.keys())         # 打印字典的键
print(_dict.values())       # 打印字典的值

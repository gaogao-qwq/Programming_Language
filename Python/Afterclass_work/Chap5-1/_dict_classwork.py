_dict = {"name": "张三", "age": 20}
_dict["age"] = 30
_dict["major"] = "软件工程"

if "c" in _dict:
    print("c 是 _dict 的键")
else:
    print("c 不是 _dict 的键")

print("_dict 的长度：" + str(len(_dict)))

for i in _dict:
    print("{key}---{value}".format(key=i, value=_dict[i]))

_dict.clear()
print(_dict)

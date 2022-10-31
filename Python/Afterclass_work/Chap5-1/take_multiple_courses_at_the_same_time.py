set1 = {'张三', '李四', '王五', '马六', '赵七', '钱八'}
set2 = {'姬一', '孙必', '周冲', '王五', '方向', '张玉'}
set3 = {'刘玉', '王五', '方向', '孙身', '陈红', '马六'}
_hash = {}
_not_selected = 25 - len(set1 | set2 | set3)
_1_at_same_time = 0
_2_at_same_time = 0
_3_at_same_time = 0

# 我知道这很不 pythonic 但我就是想用哈希表

for i in set1:
    if not _hash.__contains__(i):
        _hash[i] = 1
        continue
    _hash[i] += 1

for i in set2:
    if not _hash.__contains__(i):
        _hash[i] = 1
        continue
    _hash[i] += 1

for i in set3:
    if not _hash.__contains__(i):
        _hash[i] = 1
        continue
    _hash[i] += 1

for i in _hash:
    if _hash.get(i) == 1:
        _1_at_same_time += 1
    if _hash.get(i) == 2:
        _2_at_same_time += 1
    if _hash.get(i) == 3:
        _3_at_same_time += 1

print("有{n}位学生没有选课".format(n=_not_selected))
print("有{n}位学生同时选了1门课".format(n=_1_at_same_time))
print("有{n}位学生同时选了2门课".format(n=_2_at_same_time))
print("有{n}位学生同时选了3门课".format(n=_3_at_same_time))

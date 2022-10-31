# 插入排序，时间复杂度O(N^2)，空间复杂度O(1)。
def insertion_sort(_arr):
    for i in range(1, len(_arr)):
        key = _arr[i]
        j = i - 1
        while j >= 0 and key < _arr[j]:
            _arr[j + 1] = _arr[j]
            j -= 1
        _arr[j + 1] = key


_arr = [12, 11, 13, 5, 6]
insertion_sort(_arr)
print("排序后的数组:")
print(_arr)

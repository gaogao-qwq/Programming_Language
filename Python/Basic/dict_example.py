mmap = dict()
count = 0
nums = [1, 2, 2, 3, 4, 4, 4, 4, 5, 6, 7, 7, 7, 8]
for i in nums:
    if i not in mmap:
        mmap[i] = 1
    else:
        mmap[i] += 1

print(mmap)

for i in mmap:
    if mmap[i] == i:
        count += 1

print(count)

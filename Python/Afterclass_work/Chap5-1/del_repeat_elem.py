_hash = {}
lst = [2, 4, 7, 9, 10, 0, 1, 3, 4, 8, 7, 5, 9, 2, 4]
ans = []
for i in lst:
    if not _hash.__contains__(i):
        _hash[i] = 1
        ans.append(i)

print(ans)

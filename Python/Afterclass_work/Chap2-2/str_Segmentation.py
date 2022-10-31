def segment_str(_str):
    i = j = 0
    if not (_str.count('-')):
        return _str
    for i in range(len(_str)):
        if _str[i] == '-':
            break
    for j in range(len(_str)):
        if _str[-j] == '-':
            break
    return _str[:i] + '+' + _str[-j + 1:]


print(segment_str(input("Input a string and separate each word with '-': ")))

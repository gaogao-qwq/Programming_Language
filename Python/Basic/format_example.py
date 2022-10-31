import datetime
# 按位置访问参数
print('{0}, {1}, {2}'.format('a', 'b', 'c'))
print('{}, {}, {}'.format('a', 'b', 'c'))
print('{2}, {1}, {0}'.format('a', 'b', 'c'))
print('{0}, {1}, {2}'.format(*'abc'))  # unpacking argument sequence
print('{0}{1}{0}'.format('abra', 'cad'))  # arguments' indices can be repeated

# 按名称访问参数
print('Coordinates: {latitude}, {longitude}'
      .format(latitude='37.24N', longitude='-115.81W'))
coord = {'latitude': '37.24N', 'longitude': '-115.81W'}
print('Coordinates: {latitude}, {longitude}'.format(**coord))

# 访问参数的属性
c = 3 - 5j
print(('The complex number {0} is formed from the real part {0.real} '
      'and the imaginary part {0.imag}.').format(c))

# 访问参数的项
coord = (3, 5)
print('X: {0[0]}, Y: {0[1]}'.format(coord))

# 替代 %r %s
text1 = "text1"; text2 = "text2"
print("repr() shows quotes: {!r}; str() doesn't: {!s}"
      .format('test1', 'test2'))

# 对齐文本以及指定宽度
print('{:<30}'.format('left aligned'))
print('{:>30}'.format('right aligned'))
print('{:^30}'.format('centered'))
print('{:*^30}'.format('centered'))  # use '*' as a fill char

# 替代 %+f, %-f 和 % f 以及指定正负号
print('{:+f}; {:+f}'.format(3.14, -3.14))
print('{:f}; {:f}'.format(3.14, -3.14))
print('{:-f}; {:-f}'.format(3.14, -3.14))

# 替代 %x 和 %o 以及转换基于不同进位制的值
# format also supports binary numbers
print("int: {0:d}; hex: {0:x}; oct: {0:o}; bin: {0:b}".format(42))
# with 0x, 0o, or 0b as prefix:
print("int: {0:d}; hex: {0:#x}; oct: {0:#o}; bin: {0:#b}".format(42))

# 使用逗号作为千位分隔符
print('{:,}'.format(1234567890))

# 表示为百分数
points = 19; total = 22
print('Correct answers: {:.2%}'.format(points/total))

# 使用特定类型的专属格式化
d = datetime.datetime(2010, 7, 4, 12, 15, 58)
print('{:%Y-%m-%d %H:%M:%S}'.format(d))

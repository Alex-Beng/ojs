# slice notation 切片符号

```python
nums = list(range(10))
nums[low:high:stride]
nums[::-1]
nums[::2]
nums[1::2]
```

# zip() 与 zip(*)


[Iterate over several iterables in parallel, producing tuples with an item from each one.](https://docs.python.org/3/library/functions.html#zip)

Another way to think of zip() is that it turns rows into columns, and columns into rows. This is similar to transposing a matrix.

压缩与解压缩，可用于二维矩阵获得col，或者理解为转置矩阵。


```python
a = [1,2,3]
b = [4,5,6]
c = [4,5,6,7,8]

zipped = zip(a,b)
zipped = list(zipped)
'''
打包为元组的列表
>>> [(1, 4), (2, 5), (3, 6)]
'''

zip(a,c)
'''
元素个数与最短的列表一致
>>> [(1, 4), (2, 5), (3, 6)]
'''

zip(*zipped)
'''
zip() in conjunction with the * operator can be used to unzip a list:

与 zip 相反，可理解为解压，返回二维矩阵式
>>> [(1, 2, 3), (4, 5, 6)]
'''
```

## 衍生

矩阵转置，旋转etc

```python
a = [[1,2,3], [4,5,6]] # 可视为已经压缩了
list(zip(*a))       # 转置
list(zip(*a[::-1])) # 顺时针90°
list(zip(*a))[::-1] # 逆时针90°
```
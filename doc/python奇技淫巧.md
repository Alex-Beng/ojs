# slice notation 切片符号

```python
nums = list(range(10))
nums[low:high:stride]
nums[::-1]
nums[::2]
nums[1::2]
```

# zip() 与 zip(*)

压缩与解压缩，可用于二维矩阵获得col

```python
>>>a = [1,2,3]
>>> b = [4,5,6]
>>> c = [4,5,6,7,8]
>>> zipped = zip(a,b)     # 打包为元组的列表
[(1, 4), (2, 5), (3, 6)]
>>> zip(a,c)              # 元素个数与最短的列表一致
[(1, 4), (2, 5), (3, 6)]
>>> zip(*zipped)          # 与 zip 相反，可理解为解压，返回二维矩阵式
[(1, 2, 3), (4, 5, 6)]
```

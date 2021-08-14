```python
n = len(nums)
nums.sort()
L = 0
R = n-1
# t is the query num
while L<=R:
    m = L + (R-L)//2
    if nums[m] > t:
        R = m-1
    elif nums[m] < t:
        L = m+1
    else:
        # m is the ans
        break
```

实际上获得的 L 有nums[L] >= t， R 有nums[R] <= t。
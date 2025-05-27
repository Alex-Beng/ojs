class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        if m <= n:
            k = n // m
            return (1+n) * n // 2 - (m+m*k)*k
        else:
            # 说明没有可以被m整除的
            return (1+n) * n // 2

INPUT = [
    (10, 3),
    (5, 6),
    (5, 1)
]
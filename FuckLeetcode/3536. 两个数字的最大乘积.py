class Solution:
    def maxProduct(self, n: int) -> int:
        base = 1
        nums = []
        while True:
            if base > n:
                break
            
            lb = (n // base) % 10
            nums.append(lb)
            base *= 10
        nums.sort()
        a, b = nums[-2:]
        return a*b

INPUT = [
    (31, ),
    (437, ),
]
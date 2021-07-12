class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        nums = [start+ 2*i for i in range(n)]
        ans = 0
        for n in nums:
            ans ^= n
        return ans
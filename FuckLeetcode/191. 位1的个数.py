class Solution:
    def hammingWeight(self, n: int) -> int:
        ans = 0
        for i in range(32):
            ans += n%2
            n //= 2
        return ans
    def hammingWeight(self, n: int) -> int:
        ans = 0
        while n:
            n &= n-1
            ans += 1
        return ans
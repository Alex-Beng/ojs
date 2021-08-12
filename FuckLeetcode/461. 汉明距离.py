class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        t = x^y
        ans = 0
        while t:
            t &= (t-1)
            ans += 1
        return ans
s = Solution()
print(s.hammingDistance(
    # 1, 4
    3,1
))
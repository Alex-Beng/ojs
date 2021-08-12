class Solution:
    def arraySign(self, nums: [int]) -> int:
        ans = 1
        for n in nums:
            if not n:
                return 0
            ans *= (n/abs(n))
        return int(ans)
s = Solution()
print(s.arraySign(
    #  [-1,-2,-3,-4,3,2,1]
    #  [1,5,0,2,-3]
     [-1,1,-1,1,-1]
))
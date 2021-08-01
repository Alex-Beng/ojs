class Solution:
    def numberOfArithmeticSlices(self, nums) -> int:
        n = len(nums)
        delta_n = [None] + [nums[i]-nums[i-1] for i in range(1, n)]
        dp = [0]*n

        if n <= 2:
            return 0
        
        for i in range(2, n):
            if delta_n[i] == delta_n[i-1]:
                dp[i] = dp[i-1]+1
        
        return sum(dp)
s = Solution()
print(s.numberOfArithmeticSlices(
     [1,2,3,4]
))
        
class Solution:
    def jump(self, nums) -> int:
        n = len(nums)
        dp = [float('inf')]*n
        dp[0] = 0
        for i in range(n):
            for j in range(i, min(i+nums[i]+1, n)):
                # print(j)
                dp[j] = min(dp[i]+1, dp[j])
        # print(dp)
        return dp[n-1]
s = Solution()
print(s.jump([2,3,1,1,4]))
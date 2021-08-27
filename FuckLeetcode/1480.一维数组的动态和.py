class Solution:
    def runningSum(self, nums: [int]) -> [int]:
        n = len(nums)
        dp = [nums[0]]*n
        for i in range(1, n):
            dp[i] = dp[i-1]+nums[i]
        return dp
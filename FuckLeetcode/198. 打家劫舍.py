class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        dp = [0]*(n)
        dp[0] = nums[0]
        dp[1] = nums[1] if nums[1]>nums[0] else nums[0]
        for i in range(2, n):
            dp[i] = max(dp[i-2]+nums[i], dp[i-1])
        return dp[n-1]
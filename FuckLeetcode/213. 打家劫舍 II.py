class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1 or n == 2:
            return max(nums)
        
        dp = [0]*(n)
        dp[0] = nums[0]
        dp[1] = nums[1] if nums[1]>nums[0] else nums[0]
        for i in range(2, n-1):
            dp[i] = max(dp[i-2]+nums[i], dp[i-1])
        ans = dp[n-2]

        dp = [0]*n
        dp[1] = nums[1]
        dp[2] = nums[2] if nums[2]>nums[1] else nums[1]
        for i in range(3, n):
            dp[i] = max(dp[i-2]+nums[i], dp[i-1])
        
        return max(ans, dp[n-1])
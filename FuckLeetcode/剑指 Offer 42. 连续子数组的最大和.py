class Solution:
    def maxSubArray(self, nums) -> int:
        # dp[i]: nums[i] 结尾的最大和
        # dp[i] = max(dp[i-1], nums[i])
        dp = [0]
        for n in nums:
            dp.append(max(dp[-1]+n, n))
        # print(max(dp))
        return max(dp[1:]) if len(dp[1:]) != 0 else nums[0]
s = Solution()
s.maxSubArray([-2])
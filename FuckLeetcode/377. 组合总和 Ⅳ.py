class Solution:
    def combinationSum4(self, nums, target: int) -> int:
        n = len(nums)
        dp = [0]*(target+max(nums)+233)
        dp[0] = 1

        for i in range(0, target+1):
            for c in nums:
                dp[i+c] += dp[i]
            # print(dp)
        return dp[target]

s = Solution()
print(s.combinationSum4(
    # [1,2,3], 4
    [9], 3
))
class Solution:
    def subarraySum(self, nums: [int], k: int) -> int:
        n = len(nums)
        dp = [nums[0]]*(n+1)
        for i in range(1, n):
            dp[i] = dp[i-1] + nums[i]
        dp_times = dict()
        dp_times[0] = 1
        ans = 0
        for j in range(n):
            dpi = dp[j]-k
            if dpi in dp_times:
                ans += dp_times[dpi]

            if dp[j] in dp_times:
                dp_times[dp[j]] += 1
            else:
                dp_times[dp[j]] = 1

        return ans
s = Solution()
print(s.subarraySum(
    # [1,1,1], 2
    [1,2,3], 3
))
        
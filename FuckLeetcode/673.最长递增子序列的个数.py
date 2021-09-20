#
# @lc app=leetcode.cn id=673 lang=python3
#
# [673] 最长递增子序列的个数
#

# @lc code=start
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1]*(n+1)
        cnt = [1]*(n+1)
        for i in range(1, n):
            for j in range(i):
                if nums[j] < nums[i]:
                    if dp[j]+1 > dp[i]:
                        dp[i] = dp[j]+1
                        cnt[i] = cnt[j]
                    elif dp[j]+1 == dp[i]:
                        cnt[i] += cnt[j]
        # print(dp)
        # print(cnt)
        max_len = max(dp)
        ans = 0
        for i in range(n):
            if dp[i] == max_len:
                ans += cnt[i]
        return ans
# @lc code=end


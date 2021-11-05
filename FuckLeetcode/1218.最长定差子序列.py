#
# @lc app=leetcode.cn id=1218 lang=python3
#
# [1218] 最长定差子序列
#

# @lc code=start
class Solution:
    def longestSubsequence(self, arr: [int], difference: int) -> int:
        num2time = dict()
        ans = -1
        for n in arr:
            if n-difference in num2time:
                if n in num2time:
                    num2time[n] = max(num2time[n], num2time[n-difference]+1)
                else:
                    num2time[n] = num2time[n-difference]+1
            else:
                num2time[n] = 1
            ans = max(ans, num2time[n])
        return ans
# @lc code=end


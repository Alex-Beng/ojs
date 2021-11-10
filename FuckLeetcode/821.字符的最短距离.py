#
# @lc app=leetcode.cn id=821 lang=python3
#
# [821] 字符的最短距离
#

# @lc code=start
class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        n = len(s)
        dp = [float('inf') if s[i]!=c else 0 for i in range(n)]
        for i in range(1, n):
            dp[i] = min(dp[i], dp[i-1]+1)
        for i in range(n-2, -1, -1):
            dp[i] = min(dp[i], dp[i+1]+1)
        return dp
# @lc code=end


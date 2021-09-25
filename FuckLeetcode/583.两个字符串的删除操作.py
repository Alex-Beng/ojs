#
# @lc app=leetcode.cn id=583 lang=python3
#
# [583] 两个字符串的删除操作
#

# @lc code=start
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n1 = len(word1)
        n2 = len(word2)
        dp = [[0]*n2 for _ in range(n1)]
        
        dp[0][0] = 1 if word1[0]==word2[0] else 0
        for i in range(1, n2):
            if word2[i] == word1[0] or dp[0][i-1]:
                dp[0][i] = 1
        for i in range(1, n1):
            if word1[i] == word2[0] or dp[i-1][0]:
                dp[i][0] = 1

        for i in range(1, n1):
            for j in range(1, n2):
                if word1[i] == word2[j]:
                    dp[i][j] = dp[i-1][j-1]+1
                else:
                    dp[i][j] = max(
                        dp[i-1][j],
                        dp[i][j-1],
                        dp[i-1][j-1]
                    )
        # for r in dp:
        #     print(r)
        return n1+n2-dp[n1-1][n2-1]*2
# @lc code=end


class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0]*(n+7)
        dp[0] = 1
        dp[1] = 1
        dp[2] = 2
        
        for i in range(3, n+1):
            for j in range(0, i):
                dp[i] += dp[i-1-j]*dp[j]
        return dp[n]
s = Solution()
print(s.numTrees(4))
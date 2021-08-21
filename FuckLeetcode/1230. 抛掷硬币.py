class Solution:
    def probabilityOfHeads(self, prob: [float], target: int) -> float:
        n = len(prob)
        dp = [[0.0]*(n+1) for _ in range(n)]
        dp[0][0] = 1-prob[0]
        dp[0][1] = prob[0]
        for i in range(1, n):
            dp[i][0] = dp[i-1][0]*(1-prob[i])
            for j in range(1, i+2):
                dp[i][j] = dp[i-1][j]*(1-prob[i]) + dp[i-1][j-1]*prob[i]
        
        # print(dp)
        return dp[-1][target]
s = Solution()
print(s.probabilityOfHeads(
     [0.4], 1
    # [0.5,0.5,0.5,0.5,0.5], 0
))
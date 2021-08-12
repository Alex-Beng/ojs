class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [0]*(n+4)
        dp[2] = 1
        dp[3] = 2
        for i in range(4, n+1):
            for j in range(1, i):
                
                jj = i-j
                # print(i, j, jj)
                t_ans = max(
                            dp[jj]*dp[j],
                            dp[jj]*j,
                            jj*dp[j],
                            jj*j
                            )
                dp[i] = max(t_ans, dp[i])
            # print(dp)
        return dp[n]
s = Solution()
print(s.integerBreak(
    # 10
    2
))
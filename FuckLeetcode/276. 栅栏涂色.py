class Solution:
    def numWays(self, n: int, k: int) -> int:
        dp = [0]*(n+233)
        dp[0] = 1
        dp[1] = k
        dp[2] = k
        for i in range(1, n+1):
            dp[i+1] += dp[i]*(k-1)
            dp[i+2] += dp[i]*(k-1)
        # print(dp)
        return dp[n]
s = Solution()
print(s.numWays(
    # 3, 2
    #
    #  1,1
    7,2
))
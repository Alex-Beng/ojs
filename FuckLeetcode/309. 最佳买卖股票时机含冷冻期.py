class Solution:
    def maxProfit(self, prices) -> int:
        n = len(prices)
        dp = [[0,0,0] for i in range(n)]
        dp[0][0] = -prices[0]
        # print(dp[0])
        for i in range(1, n):
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]-prices[i])
            dp[i][1] = dp[i-1][0]+prices[i]
            dp[i][2] = max(dp[i-1][1], dp[i-1][2])
            print(dp[i])
        return max(dp[n-1]) if max(dp[n-1])>0 else 0
s = Solution()
print(s.maxProfit(
     [1,2,3,0,2]
    # [4,2,1]
    # [2,1,2,0,1]

))
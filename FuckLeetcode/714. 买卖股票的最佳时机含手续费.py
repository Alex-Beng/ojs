class Solution:
    def maxProfit(self, prices, fee) -> int:
        n = len(prices)
        dp = [[0,0] for i in range(n)]
        dp[0][0] = -prices[0]
        # print(dp[0])
        for i in range(1, n):
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i])
            dp[i][1] = max(dp[i-1][0]+prices[i]-fee, dp[i-1][1])

        return max(dp[n-1]) if max(dp[n-1])>0 else 0
s = Solution()
print(s.maxProfit(
    [1, 3, 2, 8, 4, 9]
    #  [1,2,3,0,2]
    # [4,2,1]
    # [2,1,2,0,1]
    ,
    2
))
class Solution:
    def maxProfit(self, prices: [int]) -> int:
        n = len(prices)
        dp = [[float('-inf')]*2 for i in range(n)]
        dp[0][0] = -prices[0]

        for i in range(1, n):
            dp[i][0] = max(-prices[i], dp[i-1][0])
            dp[i][1] = max(dp[i-1][0]+prices[i], dp[i-1][1])
        
        return max(dp[n-1][1], 0)
s = Solution()
print(s.maxProfit(
    [7,1,5,3,6,4]
))

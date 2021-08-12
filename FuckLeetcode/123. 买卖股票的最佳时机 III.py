class Solution:
    def maxProfit(self, prices) -> int:
        n = len(prices)
        dp = [[float('-inf')]*5 for i in range(n)]
        dp[0][1] = -prices[0]
        for t in range(1, n):
            dp[t][1] = max(0-prices[t], dp[t-1][1])
            dp[t][2] = max(dp[t-1][1]+prices[t], dp[t-1][2])
            dp[t][3] = max(dp[t-1][2]-prices[t], dp[t-1][3])
            dp[t][4] = max(dp[t-1][3]+prices[t], dp[t-1][4])

            print(dp)
        return max(max(dp[n-1]), 0)
    

s = Solution()
print(s.maxProfit(
    # [3,3,5,0,0,3,1,4]
    # [1,2,3,4,5]
    # [7,6,4,3,1] 
    # [1]
    # [1,2,4,2,5,7,2,4,9,0]
    [2,1,4]
))
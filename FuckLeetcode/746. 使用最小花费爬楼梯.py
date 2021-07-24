class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0]*(n+3)
        for i in range(2, n+1):
            dp[i] = min(cost[n-2]+dp[n-2], cost[n-1]+dp[n-1])
        return dp[n]
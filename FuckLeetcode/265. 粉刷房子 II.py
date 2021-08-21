class Solution:
    def minCostII(self, costs: [[int]]) -> int:
        n = len(costs)
        k = len(costs[0])

        dp = [[0]*k for _ in range(n)]
        for i in range(k):
            dp[0][i] = costs[0][i]
        
        for i in range(1, n):
            for j in range(k):
                t_min = float('inf')
                for m in range(k):
                    if j!=m:
                        t_min = min(t_min, dp[i-1][m]+costs[i][j]) 
                dp[i][j] = t_min
        # print(dp)
        return min(dp[-1])
s = Solution()
s.minCostII(
    [[1,5,3],[2,9,4]]
)
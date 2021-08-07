class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid) -> int:
        row = len(obstacleGrid)
        col = len(obstacleGrid[0])
        dp = [[0]*(col) for i in range(row)]
        dp[0][0] = 1
        for r in range(row):
            for c in range(col):
                if obstacleGrid[r][c]:
                    dp[r][c] = 0
                else:
                    if r>=1:
                        dp[r][c] += dp[r-1][c]
                    if c>=1:
                        dp[r][c] += dp[r][c-1]
        return dp[row-1][col-1] 
s = Solution()
print(s.uniquePathsWithObstacles(
    # [[0,0,0],[0,1,0],[0,0,0]]
    [[0,1]]
))
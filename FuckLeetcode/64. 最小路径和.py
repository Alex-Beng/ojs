class Solution:
    def minPathSum(self, grid) -> int:
        row = len(grid)
        col = len(grid[0])
        
        dp = [[float('inf')]*col for i in range(row)]
        dp[0][0] = grid[0][0]
        for r in range(row):
            for c in range(col):
                if r>=1:
                    dp[r][c] = dp[r-1][c] + grid[r][c]
                if c>=1:
                    dp[r][c] = min(dp[r][c], dp[r][c-1]+grid[r][c])
        # print(dp)
        return dp[row-1][col-1]
s = Solution()
print(s.minPathSum(
    #  [[1,3,1],[1,5,1],[4,2,1]]
     [[1,2,3],[4,5,6]]
)
)
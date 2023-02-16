from typing import List

class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        row = len(grid)
        col = len(grid[0])

        # dp[i][j] [0]for row, [1]for col
        dp = [[[0, 0] for _ in range(col)] for __ in range(row)]
        dp[0][0][0] = dp[0][0][1] = grid[0][0]
        for c in range(1, col):
            dp[0][c][0] = dp[0][c-1][1]+1 if grid[0][c] else 0
            dp[0][c][1] = grid[0][c]
        for r in range(1, row):
            dp[r][0][0] = grid[r][0]
            dp[r][0][1] = dp[r-1][0][0] if grid[r][0] else 0
        for r in range(row):
            for c in range(col):
                dp[r][c][0] = dp[r][c-1][0]+1 if grid[r][c] else 0
                dp[r][c][1] = dp[r-1][c][1]+1 if grid[r][c] else 0
        ans = 0
        # 枚举所有正方形
        for r in range(row):
            for c in range(col):
                for L in range(min(row-r, col-c)):
                    if min(dp[r+L][c+L]) > L and \
                        dp[r][c+L][0] > L and \
                        dp[r+L][c][1] > L:
                        ans = max(ans, (L+1) * (L+1))
                    # print(r, c, r+L, c+L)

        # print(dp)
        # print(ans)
        return ans
s = Solution()
s.largest1BorderedSquare(
    grid = [[1,1,1],[1,0,1],[1,1,1]]
)
class Solution:
    def shiftGrid(self, grid: [[int]], k: int) -> [[int]]:
        nr = len(grid)
        nc = len(grid[0])

        def trans(grid):
            grid = [row[-1:]+row[:-1] for row in grid ]
            t = grid[nr-1][0]
            for r in range(nr-1, 0, -1):
                grid[r][0] = grid[r-1][0]
            grid[0][0] = t
            return grid
        for i in range(k):
            grid = trans(grid)
        return grid

s = Solution()
exec(
'grid = [[1,2,3],[4,5,6],[7,8,9]];k = 1'
# 'grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]; k = 4'
)
r = s.shiftGrid(grid, k)
print(r)
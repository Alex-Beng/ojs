class Solution:
    def maxAreaOfIsland(self, grid: [[int]]) -> int:
        dr = [0,0,1,-1]
        dc = [1,-1,0,0]

        row = len(grid)
        col = len(grid[0])

        def area(r, c, k):
            ans = 1
            grid[r][c] = k
            for i in range(4):
                nr = r+dr[i]
                nc = c+dc[i]
                if nr>=0 and nr<row and nc>=0 and nc<col and grid[nr][nc]==1:
                    ans += area(nr, nc, k)
            return ans
        
        island_cnt = 2
        ans = 0
        for r in range(row):
            for c in range(col):
                if grid[r][c] == 1:
                    t = area(r, c, island_cnt)
                    ans = max(ans, t)
                    island_cnt += 1
        return ans
s = Solution()
print(s.maxAreaOfIsland(
    [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
))
            
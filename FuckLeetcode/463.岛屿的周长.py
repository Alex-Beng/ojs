#
# @lc app=leetcode.cn id=463 lang=python3
#
# [463] 岛屿的周长
#

# @lc code=start
from queue import Queue
class Solution:
    def islandPerimeter(self, grid: [[int]]) -> int:
        ans = 0
        dr = [0,0,1,-1]
        dc = [1,-1,0,0]
        row = len(grid)
        col = len(grid[0])

        def bfs(r,c):
            nonlocal ans
            q = Queue()
            q.put((r,c))
            grid[r][c] = 2
            while not q.empty():
                r,c = q.get()
                for i in range(4):
                    nr, nc = r+dr[i], c+dc[i]
                    if nr==row or nr<0 or nc==col or nc<0:
                        ans += 1
                        continue
                    if grid[nr][nc] == 0:
                        ans += 1
                    elif grid[nr][nc] == 1:
                        q.put((nr,nc))
                        grid[nr][nc] = 2

        for r in range(row):
            for c in range(col):
                if grid[r][c]:
                    bfs(r,c)
                    return ans

# @lc code=end

s = Solution()
r = s.islandPerimeter(
    # [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
    [[1,1],[1,1]]

)
print(r)
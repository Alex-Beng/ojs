#
# @lc app=leetcode.cn id=1091 lang=python3
#
# [1091] 二进制矩阵中的最短路径
#

# @lc code=start
from queue import Queue
class Solution:
    def shortestPathBinaryMatrix(self, grid: [[int]]) -> int:
        row = len(grid)
        col = len(grid[0])
        step = [[float('inf')]*col for _ in range(row)]

        dr = [0,0,1,1,1,-1,-1,-1]
        dc = [1,-1,0,1,-1,0,1,-1]
        
        if grid[0][0]:
            return -1
        
        q = Queue()
        
        q.put((0,0,1))
        step[0][0] = 1
        ans = float('inf')
        while not q.empty():
            r, c, l = q.get()
            # print(r, c, l)
            if r==row-1 and c==col-1:
                # ans = min(ans, l)
                return l

            for i in range(8):
                nr = r+dr[i]
                nc = c+dc[i]
                if nr>=0 and nr<row and nc>=0 and nc<col \
                    and step[nr][nc]>l+1 and grid[nr][nc]==0:
                    # print(nr, nc, l+1)
                    step[nr][nc] = l+1
                    q.put((nr, nc, l+1))
            # print()
        return -1 if ans == float('inf') else ans
# @lc code=end

s = Solution()
res = s.shortestPathBinaryMatrix(
    [
        [0,0,0,0,1,1],
        [0,1,0,0,1,0],
        [1,1,0,1,0,0],
        [0,1,0,0,1,1],
        [0,1,0,0,0,1],
        [0,0,1,0,0,0]]

)
print(res)
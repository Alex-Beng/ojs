#
# @lc app=leetcode.cn id=407 lang=python3
#
# [407] 接雨水 II
#

# @lc code=start
from queue import PriorityQueue as pq
class Solution:
    def trapRainWater(self, heightMap: [[int]]) -> int:
        row = len(heightMap)
        col = len(heightMap[0])

        been = [[0]*col for _ in range(row)]

        que = pq()
        ans = 0

        for i in range(col):
            been[0][i] = been[row-1][i] = 1
            que.put( (heightMap[0][i], 0, i) )
            que.put( (heightMap[row-1][i], row-1, i) )
        for j in range(1, row-1):
            been[j][0] = been[j][col-1] = 1
            que.put( (heightMap[j][0], j, 0) )
            que.put( (heightMap[j][col-1], j, col-1) )

        dr = [0,0,1,-1]
        dc = [1,-1,0,0]
        while not que.empty():
            h, r, c = que.get()
            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]
                if nr>=0 and nr<row and nc>=0 and nc<col and not been[nr][nc]:
                    # print("cao?", nr, nc, h - heightMap[nr][nc])
                    ans += max(h-heightMap[nr][nc], 0)
                    been[nr][nc] = 1
                    que.put((max(h, heightMap[nr][nc]), nr, nc))
        return ans
# @lc code=end
s = Solution()
r = s.trapRainWater(
    [[1,4,3,1,3,2],
     [3,2,1,3,2,4],
     [2,3,3,2,3,1]]
)
print(r)
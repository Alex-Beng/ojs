class Solution:
    def updateMatrix(self, mat: [[int]]) -> [[int]]:
        row = len(mat)
        col = len(mat[0])
        dist = [[float('inf') if mat[i][j] else 0 for j in range(col)] for i in range(row)]

        dr = [0,0,1,-1]
        dc = [1,-1,0,0]

        queue = []
        head = 0
        tail = -1
        for i in range(row):
            for j in range(col):
                if mat[i][j] == 0:
                    queue.append((i,j))
                    tail += 1
        while head <= tail:
            r,c = queue[head]
            head += 1
            for i in range(4):
                nr = r+dr[i]
                nc = c+dc[i]
                if nr<0 or nr>=row or nc<0 or nc>=col or dist[nr][nc] <= dist[r][c]:
                    continue
                dist[nr][nc] = min(dist[nr][nc], dist[r][c]+1)
                queue.append((nr, nc))
                tail += 1
            
        return dist
s = Solution()
res = s.updateMatrix(
    # [[0,0,0],[0,1,0],[0,0,0]]
    # [[0,0,0],[0,1,0],[1,1,1]]
    [[1,0,1,1,0,0,1,0,0,1],
     [0,1,1,0,1,0,1,0,1,1],
     [0,0,1,0,1,0,0,1,0,0],
     [1,0,1,0,1,1,1,1,1,1],
     [0,1,0,1,1,0,0,0,0,1],
     [0,0,1,0,1,1,1,0,1,0],
     [0,1,0,1,0,1,0,0,1,1],
     [1,0,0,0,1,1,1,1,0,1],
     [1,1,1,1,1,1,1,0,1,0],
     [1,1,1,1,0,1,0,0,1,1]]
)
for r in res:
    print(r)

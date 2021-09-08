class Solution:
    def orangesRotting(self, grid: [[int]]) -> int:
        row = len(grid)
        col = len(grid[0])

        dr = [0,0,1,-1]
        dc = [1,-1,0,0]

        queue = []
        head = 0
        tail = -1
        time = [[0]*col for i in range(row)]

        for r in range(row):
            for c in range(col):
                if grid[r][c] == 2:
                    queue.append((r,c))
                    tail += 1
                    time[r][c] = 0
                elif grid[r][c] == 1:
                    time[r][c] = float('inf')
                else:
                    time[r][c] = -1
        

        while head <= tail:
            r, c = queue[head]
            head += 1
            for i in range(4):
                nr = r+dr[i]
                nc = c+dc[i]
                if nr<0 or nr>=row or nc<0 or nc>=col \
                    or grid[nr][nc]==0 or time[nr][nc] <= time[r][c]:
                    continue
                time[nr][nc] = min(time[nr][nc], time[r][c]+1)
                queue.append((nr, nc))
                tail += 1
        
        time_max = max([max(r) for r in time])
        if time_max == float('inf'):
            return -1
        elif time_max == -1:
            return 0
        else:
            return time_max

s = Solution()
ya = s.orangesRotting(
    # [[2,1,1],[1,1,0],[0,1,1]]
    # [[2,1,1],[0,1,1],[1,0,1]]
    # [[0,2]]
    [[0]]
)
print(ya)
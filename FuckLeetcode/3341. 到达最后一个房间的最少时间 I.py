import queue
class Solution:
    def minTimeToReach(self, moveTime: 'List[List[int]]') -> int:
        R = len(moveTime)
        C = len(moveTime[0])

        currMin = [[float('inf')] * C for _ in range(R)]
        qrq = queue.PriorityQueue()
        qrq.put((0, 0, 0))
        
        dxs = [0, 0, 1, -1]
        dys = [1, -1, 0, 0]
        while not qrq.empty():
            t, r, c = qrq.get()
            if t < currMin[r][c]:
                currMin[r][c] = t
                for i in range(4):
                    nr = r + dxs[i]
                    nc = c + dys[i]
                    if 0 <= nr and nr < R and 0 <= nc and nc < C:
                        nt = max(t + 1, moveTime[nr][nc] + 1)
                        if nt < currMin[nr][nc]:
                            qrq.put( (nt, nr, nc) )
        return currMin[R-1][C-1]

INPUT = [
    ([[0,4],[4,4]], ),
    ([[0,0,0],[0,0,0]], ),
    ([[94,79,62,27,69,84],
      [6,32,11,82,42,30]], )
]
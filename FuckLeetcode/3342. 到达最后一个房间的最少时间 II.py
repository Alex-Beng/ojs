import queue
class Solution:
    def minTimeToReach(self, moveTime: 'List[List[int]]') -> int:
        R = len(moveTime)
        C = len(moveTime[0])

        currMin = [[float('inf')] * C for _ in range(R)]
        qrq = queue.PriorityQueue()
        qrq.put((0, 1, 0, 0))
        
        dxs = [0, 0, 1, -1]
        dys = [1, -1, 0, 0]
        while not qrq.empty():
            t, cs, r, c = qrq.get()
            # print(t, cs, r, c)
            ncs = 2 if cs == 1 else 1
            for i in range(4):
                nr = r + dxs[i]
                nc = c + dys[i]
                if 0 <= nr and nr < R and 0 <= nc and nc < C:
                    nt = max(t + cs, moveTime[nr][nc] + cs)
                    if nt < currMin[nr][nc] or moveTime[nr][nc] == float('inf'):
                        currMin[nr][nc] = nt
                        if nr == R-1 and nc == C-1:
                            return nt
                        qrq.put( (nt, ncs, nr, nc) )
        print(currMin)
        return currMin[R-1][C-1]

INPUT = [
    ([[0,4],[4,4]], ),
    ([[0,0,0],[0,0,0]], ),
    ([[94,79,62,27,69,84],
      [6,32,11,82,42,30]], ),
    ([[0,58],[27,69]],),
]
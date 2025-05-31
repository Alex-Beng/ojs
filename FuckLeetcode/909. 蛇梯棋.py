from typing import List
import heapq

class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        N = len(board)
        dis = [float('inf')] * (N * N+1)
        qrq = []

        heapq.heappush(qrq, (0, 1))
        
        def i2rc(i):
            r = (i-1) // N
            c = (i-1) % N
            if r&1:
                c = (N-1) - c
            r = (N-1) - r
            return r, c

        while qrq:
            d, i = heapq.heappop(qrq)
            if d >= dis[i]:
                continue
            dis[i] = d
            for s in range(1, 7):
                ni = i + s
                if ni > N*N:
                    break
                nr, nc = i2rc(ni)
                if board[nr][nc] != -1:
                    heapq.heappush(qrq, (d+1, board[nr][nc]))
                else:
                    heapq.heappush(qrq, (d+1, ni))
        dis[N*N] = -1 if  dis[N*N] == float('inf') else dis[N*N]
        return dis[N*N]
        pass
INPUT = [
    ([[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]], ),
    ([[1,1,-1],[1,1,1],[-1,1,1]], )
]
from typing import List

class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        R = len(grid)
        C = len(grid[0])
        rowSum = [0] * R
        colSum = [0] * C
        n2pos = {}
        for r in range(R):
            for c in range(C):
                n = grid[r][c]
                rowSum[r] += n
                colSum[c] += n
                
                na = n2pos.get(n, [])
                na.append((r, c))
                n2pos[n] = na
                
        dpR = [0] * (R+1)
        dpC = [0] * (C+1)
        for r in range(1, R+1):
            dpR[r] = dpR[r-1] + rowSum[r-1]
        for c in range(1, C+1):
            dpC[c] = dpC[c-1] + colSum[c-1]

        for r in range(1, R):
            lp = dpR[r]
            rp = dpR[R] - dpR[r]
            if lp == rp:
                return True
            elif lp < rp:
                delta = rp - lp
                for dr, dc in n2pos.get(delta, []):
                    if dr < r:
                        continue
                    if R - r == 1 and dc not in [0, C-1]:
                        continue
                    if C == 1 and dr not in [r, R-1]:
                        continue
                    return True
            elif lp > rp:
                delta = lp - rp
                for dr, dc in n2pos.get(delta, []):
                    if dr >= r:
                        continue
                    if r == 1 and dc not in [0, C-1]:
                        continue
                    if C == 1 and dr not in [0, r-1]:
                        continue
                    return True
                
        for c in range(1, C):
            lp = dpC[c]
            rp = dpC[C] - dpC[c]
            if lp == rp:
                return True
            elif lp < rp:
                delta = rp - lp
                for dr, dc in n2pos.get(delta, []):
                    if dc < c:
                        continue
                    if C - c == 1 and dr not in [0, R-1]:
                        continue
                    if R == 1 and dc not in [c, C-1]:
                        continue
                    return True
            elif lp > rp:
                delta = lp - rp
                for dr, dc in n2pos.get(delta, []):
                    if dc >= c:
                        continue
                    if c == 1 and dr not in [0, R-1]:
                        continue
                    if R == 1 and dc not in [0, c-1]:
                        continue
                    return True
        return False
INPUT = [
    # ([[1,2],[3,4]], )
    # ([[29700],[29700]], )
    # ([[10,5,4,5]], )
    # ([[100000],[86218],[100000]], )
    ([[100000],[100000],[100000],[100000],[1]], )
]
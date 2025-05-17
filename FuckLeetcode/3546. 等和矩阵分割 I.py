from typing import List

class Solution:
    def canPartitionGrid(self, grid: List[List[int]]) -> bool:
        R = len(grid)
        C = len(grid[0])
        rowSum = [0] * R
        colSum = [0] * C
        for r in range(R):
            for c in range(C):
                rowSum[r] += grid[r][c]
                colSum[c] += grid[r][c]
        dpR = [0] * (R+1)
        dpC = [0] * (C+1)
        for r in range(1, R+1):
            dpR[r] = dpR[r-1] + rowSum[r-1]
        for c in range(1, C+1):
            dpC[c] = dpC[c-1] + colSum[c-1]

        print(rowSum, colSum, dpR, dpC)
        for r in range(1, R):
            # print(rowSum[r], rowSum[R-1])
            if dpR[r] * 2 == dpR[R]:
                return True
        for c in range(1, C):
            if dpC[c] * 2 == dpC[C]:
                return True
        return False
INPUT = [
    ([[1,4],[2,3]], ),
    ([[54756,54756]], )
]
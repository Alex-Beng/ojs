from typing import List

class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        grids = [[0] * n for _ in range(m)]
        for r, c in walls + guards:
            grids[r][c] = -1

        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for r, c in guards:
            
            def valid_pos(_r, _c):
                return 0 <= _r < m and 0 <= _c < n

            for dr, dc in dirs:
                cnt = 1
                while valid_pos(nr := (r + dr*cnt), nc := (c + dc*cnt)) and grids[nr][nc] >= 0:
                    grids[nr][nc] = 1
                    cnt += 1
        ans = 0
        for R in grids:
            # print(R)
            for i in R:
                if not i:
                    ans += 1
        return ans     

INPUT = [
    (4, 6, [[0,0],[1,1],[2,3]], [[0,1],[2,2],[1,4]])
]
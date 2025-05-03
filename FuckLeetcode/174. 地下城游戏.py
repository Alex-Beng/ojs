from functools import lru_cache

class Solution:
    def calculateMinimumHP(self, dungeon: 'List[List[int]]') -> int:
        R = len(dungeon)
        C = len(dungeon[0])

        
        dr = [0, 1]
        dc = [1, 0]

        @lru_cache(None)
        def validPos(r: int, c: int) -> bool:
            return 0 <= r and r < R and 0<=c and c < C

        @lru_cache(None)
        def dfs(r: int, c: int) -> int:
            if r == R-1 and c == C-1:
                return max(1 - dungeon[r][c], 1)
            minHealthy = float('inf')
            for i in range(2):
                nr = r + dr[i]
                nc = c + dc[i]
                if validPos(nr, nc):
                    minHealthy = min(minHealthy, dfs(nr, nc))
            
            return max(minHealthy - dungeon[r][c], 1)
        return dfs(0, 0)

s = Solution()
r = s.calculateMinimumHP(
    [[-2,-3,3],
     [-5,-10,1],
     [10,30,-5]]
)
print(r)

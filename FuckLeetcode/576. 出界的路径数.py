from functools import lru_cache

class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        delta = [
            [0,1],
            [0,-1],
            [1,0],
            [-1,0]
        ]
        def in_grid(r, c):
            if r>=m or r<0 or c>=n or c<0:
                return False
            else:
                return True

        @lru_cache(None)
        def memo_search(r, c, mv_step):
            if not in_grid(r, c):
                return 1
            if mv_step == 0:
                return 0
            t_ans = 0
            for d in delta:
                n_r = r + d[0]
                n_c = c + d[1]
                t_ans += memo_search(n_r, n_c, mv_step-1)

            return t_ans
        print(memo_search(startRow, startColumn, maxMove))
        return int((memo_search(startRow, startColumn, maxMove))%(10**9 + 7))



s = Solution()
print(s.findPaths(
    # 2,2,2,0,0
    # 1,3,3,0,1
    # 8,4,10,5,0
    # 8,7,16,1,5
    # 1,3,3,0,1
    # 8,50,23,5,26
    36,5,50,15,3
))

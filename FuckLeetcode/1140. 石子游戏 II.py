from typing import List
from functools import cache

class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        # 只返回sum！！
        # 傻呗做法
        @cache
        def dfs(beg_idx: int, M: int) -> (int, int, int):
            
            if beg_idx + 2*M >= n:
                # print(f'beg: {beg_idx}, M: {M}')
                # print(n, M, sum(piles[beg_idx:]))
                # print()
                return n, M, sum(piles[beg_idx:])
            t_ans_idx = 0
            t_ans_M = 0
            t_ans = 0
            for x in range(1, 2*M+1):
                bob_idx = beg_idx + x
                a_second_idx, tM, _ = dfs(bob_idx, max(M, x))
                if a_second_idx != n:                    
                    _, _, tsum =  dfs(a_second_idx, tM)
                else:
                    tsum = 0
                if tsum+sum(piles[beg_idx:beg_idx+x]) > t_ans:
                    t_ans_idx = beg_idx + x
                    t_ans_M = max(M, x)
                    t_ans = tsum+sum(piles[beg_idx:beg_idx+x])
            # print(f'beg: {beg_idx}, M: {M}')
            # print(t_ans_idx, t_ans_M, t_ans)
            # print()
            return t_ans_idx, t_ans_M, t_ans

        # print(dfs(0, 1))
        return dfs(0, 1)[-1]
s = Solution()
r = s.stoneGameII(
    #  [2,7,9,4,4]
    # [1,2,3,4,5,100]
    [2,7,9,4,4]
)
print(r)
#
# @lc app=leetcode.cn id=638 lang=python3
#
# [638] 大礼包
#

# @lc code=start
from functools import lru_cache

class Solution:
    def shoppingOffers(self, price: [int], special: [[int]], needs: [int]) -> int:
        n = len(price)
        sp_n = len(special)

        ans = float('inf')
        @lru_cache(None)
        def dfs(need: tuple, k: int) -> int:
            if k==0:
                tp = 0
                for i in range(n):
                    tp += need[i]*price[i]
                return tp

            k -= 1
            # use k / not
            tp = dfs(need, k)

            new_need = [need[i]-special[k][i] for i in range(n)]
            cnt = 1
            while min(new_need) >= 0:
                tp = min(tp, dfs(tuple(new_need), k)+special[k][-1]*cnt)
                new_need = [new_need[i]-special[k][i] for i in range(n)]
                cnt += 1
            return tp
        return dfs(tuple(needs), sp_n)
                    
# @lc code=end
s = Solution()
s.shoppingOffers(
    [9,9],[[1,1,1]],[2,2]
)


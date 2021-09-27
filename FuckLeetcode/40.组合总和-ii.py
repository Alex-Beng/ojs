#
# @lc app=leetcode.cn id=40 lang=python3
#
# [40] 组合总和 II
#

# @lc code=start
from functools import lru_cache
from copy import deepcopy
class Solution:
    def combinationSum2(self, candidates: [int], target: int) -> [[int]]:
        n = len(candidates)
        
        diff_candi = list(set(candidates))
        diff_candi.sort(reverse=True)
        candi2times = dict()

        for cd in candidates:
            if cd in candi2times:
                candi2times[cd] += 1
            else:
                candi2times[cd] = 1
        if len(diff_candi) == 1:
            return [[diff_candi[0]]*(target//diff_candi[0])] if target%diff_candi[0]==0 and candi2times[diff_candi[0]]*diff_candi[0]>=target else []
        
        L = 0
        R = len(diff_candi)-1
        ans = R
        while L<=R:
            m = (L+R)//2
            if diff_candi[m] <= target:
                ans = m
                R = m-1
            else:
                L = m+1
        # print(diff_candi, ans)
        diff_candi = diff_candi[ans:]
        dn = len(diff_candi)
        cd_used = [0]*dn
        print(candi2times, diff_candi)
        ans = []
        # @lru_cache(None)
        def dfs(depth, curr_sum, times):
            if depth == dn:
                if curr_sum == target:
                    # ans.add(tuple(times))
                    tt = []
                    for i,t in enumerate(times):
                        tt += [diff_candi[i]]*t
                    ans.append(tt)
                return
                
            cd = diff_candi[depth]

            # able to add
            if curr_sum + cd <= target:
                max_n = (target-curr_sum)//cd
                max_n = min(max_n, candi2times[cd])

                for j in range(max_n, -1, -1):
                    times[depth] = j
                    dfs(depth+1, curr_sum+j*cd, times)
                # times[i] = 0
            # else, dfs
            else:
                dfs(depth+1, curr_sum, times)
        dfs(0, 0, [0]*dn)
        return ans
# @lc code=end


s = Solution()
print(s.combinationSum2(
    # [10,1,2,7,1], 9
    [10,1,2,7,6,1,5], 8
    # [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], 27
    # [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1], 30
    # [1,1], 2
))

[7,2,1]
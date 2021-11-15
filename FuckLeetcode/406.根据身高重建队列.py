#
# @lc app=leetcode.cn id=406 lang=python3
#
# [406] 根据身高重建队列
#

# @lc code=start
from copy import deepcopy
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        n = len(people)
        pp_key = deepcopy(people)
        for i in range(n):
            pp_key[i].append(i)
        ans = []
        while len(pp_key)!=0:
            # find (min, 0)
            min_idx, min_p = min([p for p in enumerate(pp_key) if p[1][1]==0], key=lambda k: k[1])
            height, accum, pp_idx = min_p

            # add to ans
            ans.append(people[pp_idx])
            # reduce key
            for i,p in enumerate(pp_key):
                if height >= p[0]:
                    pp_key[i][1] -= 1

            del pp_key[min_idx]
        return ans
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key=lambda k: (-k[0], k[1]) )
        ans = []
        for p in people:
            heigh, accum = p
            if len(ans) <= accum:
                ans.append(p)
            else:
                ans.insert(accum, p)
        return ans
# @lc code=end
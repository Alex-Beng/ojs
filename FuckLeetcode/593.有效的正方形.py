#
# @lc app=leetcode.cn id=593 lang=python3
#
# [593] 有效的正方形
#

# @lc code=start
from collections import defaultdict
class Solution:
    def validSquare(self, p1: [int], p2: [int], p3: [int], p4: [int]) -> bool:
        dist2times = defaultdict(int)
        pnts = [p1, p2, p3, p4]
        for i in range(4):
            for j in range(i+1, 4):
                pi = pnts[i]
                pj = pnts[j]
                dist = (pi[0]-pj[0])**2 + (pi[1]-pj[1])**2
                
                dist2times[dist] += 1
        # print(dist2times.keys(), dist2times.values())
        keys = dist2times.keys()
        vals = dist2times.values()
        return min(keys)>0 and len(keys)==2 and min(vals)==2 and max(vals)==4
                
# @lc code=end

#
# @lc app=leetcode.cn id=447 lang=python3
#
# [447] 回旋镖的数量
#

# @lc code=start
class Solution:
    def numberOfBoomerangs(self, points: [[int]]) -> int:
        def dist(p1, p2):
            # return abs(p1[0]-p2[0])+abs(p1[1]-p2[1])
            return (p1[0]-p2[0])**2+(p1[1]-p2[1])**2

        n = len(points)
        # dist2times = [dict() for i in range(n)]
        ans = 0
        for i in range(n):
            dist2times = dict()
            for j in range(n):
                p1 = points[i]
                p2 = points[j]
                td = dist(p1, p2)
                if td in dist2times:
                    dist2times[td] += 1
                else:
                    dist2times[td] = 1
            for dst in dist2times:
                idxes_num = dist2times[dst]
                if idxes_num >= 2:
                    ans += idxes_num*(idxes_num-1)
        return ans

# @lc code=end


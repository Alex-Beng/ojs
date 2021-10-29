#
# @lc app=leetcode.cn id=335 lang=python3
#
# [335] 路径交叉
#

# @lc code=start
class Solution:
    def isSelfCrossing(self, distance: [int]) -> bool:
        d = distance
        n = len(d)
        for i in range(3, n):
            if d[i-3] >= d[i-1] and d[i] >= d[i-2]:
                return True
            if i>=4 and d[i-1] == d[i-3] and d[i-2] <= d[i]+d[i-4]:
                return True
            if i>=5 and d[i-3] > d[i-5] and d[i-2] > d[i-4] and d[i-1] >= d[i-3]-d[i-5] \
                and d[i-1] < d[i-3] and d[i] >= d[i-2]-d[i-4]:
                return True
        return False
# @lc code=end


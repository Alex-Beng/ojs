#
# @lc app=leetcode.cn id=1436 lang=python3
#
# [1436] 旅行终点站
#

# @lc code=start
class Solution:
    def destCity(self, paths: [[str]]) -> str:
        ios = dict()
        for f,t in paths:
            if f in ios:
                ios[f][1] += 1
            else:
                ios[f] = [0,1]
            if t in ios:
                ios[t][0] += 1
            else:
                ios[t] = [1,0]
        for k in ios:
            if ios[k][1] == 0:
                return k
# @lc code=end


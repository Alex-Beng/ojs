#
# @lc app=leetcode.cn id=1557 lang=python3
#
# [1557] 可以到达所有点的最少点数目
#

# @lc code=start
class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: [[int]]) -> [int]:
        inD = [0]*n
        for pair in edges:
            inD[pair[1]] += 1
        ans = []
        for i,d in enumerate(inD):
            if d == 0:
                ans.append(i)
        return ans
# @lc code=end


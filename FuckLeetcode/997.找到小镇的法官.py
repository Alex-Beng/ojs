#
# @lc app=leetcode.cn id=997 lang=python3
#
# [997] 找到小镇的法官
#

# @lc code=start
class Solution:
    def findJudge(self, n: int, trust: [[int]]) -> int:
        inD, outD = [0]*(n+1), [0]*(n+1)
        for pair in trust:
            inD[pair[1]] += 1
            outD[pair[0]] += 1
        ans = []
        for i in range(1, n+1):
            if inD[i]==n-1 and outD[i]==0:
                ans.append(i)
        if len(ans) == 1:
            return ans[0]
        else:
            return -1
# @lc code=end


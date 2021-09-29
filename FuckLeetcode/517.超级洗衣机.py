#
# @lc app=leetcode.cn id=517 lang=python3
#
# [517] 超级洗衣机
#

# @lc code=start
class Solution:
    def findMinMoves(self, machines: [int]) -> int:

        n = len(machines)
        cn = sum(machines)
        avg = cn//n

        inouts = [0]*(n+1)
    
        if cn%n != 0:
            return -1
        ans = 0
        for i in range(n):
            inouts[i] = machines[i]+inouts[i-1] - avg
            ans = max(ans, abs(inouts[i]))
            if inouts[i-1] < 0 and inouts[i] > 0:
                ans = max(ans, abs(inouts[i])+abs(inouts[i-1]))
            
        return ans
# @lc code=end

s = Solution()
s.findMinMoves(
    # [0,3,0]
    # [4,0,0,4]
    [9,1,8,8,9]


)
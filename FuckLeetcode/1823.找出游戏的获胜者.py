#
# @lc app=leetcode.cn id=1823 lang=python3
#
# [1823] 找出游戏的获胜者
#

# @lc code=start
class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        partner = [i for i in range(1, n+1)]
        cnt = 0
        k -= 1
        while len(partner) != 1:
            cnt += k
            cnt %= len(partner)
            del partner[cnt]
        return partner[0]
    
# @lc code=end


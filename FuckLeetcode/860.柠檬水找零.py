#
# @lc app=leetcode.cn id=860 lang=python3
#
# [860] 柠檬水找零
#

# @lc code=start
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        cashes = [0]*3
        for b in bills:
            if b==5:
                cashes[0] += 1
            elif b==10:
                cashes[0] -= 1
                cashes[1] += 1
            else:
                if cashes[1]>0:
                    cashes[1] -= 1
                    cashes[0] -= 1
                else:
                    cashes[0] -= 3
            if min(cashes) < 0:
                return False
        return min(cashes) >= 0
# @lc code=end

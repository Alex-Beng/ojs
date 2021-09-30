#
# @lc app=leetcode.cn id=441 lang=python3
#
# [441] 排列硬币
#

# @lc code=start
class Solution:
    def arrangeCoins(self, n: int) -> int:
        L = 0
        R = n
        ans = n
        while L<=R:
            m = (L+R)//2
            cn = (1+m)*m//2
            if cn>n:
                R = m-1
            elif cn<=n:
                L = m+1
                ans = m
        return ans
            
# @lc code=end


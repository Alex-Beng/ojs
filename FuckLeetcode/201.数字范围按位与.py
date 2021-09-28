#
# @lc app=leetcode.cn id=201 lang=python3
#
# [201] 数字范围按位与
#

# @lc code=start
class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        while left<right:
            right &= (right-1)
        
        return right
        
        
# @lc code=end

s = Solution()
r = s.rangeBitwiseAnd(
    # 5, 7
    # 1, 2147483647
    # 18,48
    256, 511
)
print(r)
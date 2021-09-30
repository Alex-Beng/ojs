#
# @lc app=leetcode.cn id=414 lang=python3
#
# [414] 第三大的数
#

# @lc code=start
class Solution:
    def thirdMax(self, nums: [int]) -> int:
        mx1 = float('-inf')
        mx2 = float('-inf')
        mx3 = float('-inf')
        for n in nums:
            if n > mx1:
                mx3 = mx2
                mx2 = mx1
                mx1 = n
            elif n < mx1 and n > mx2:
                mx3 = mx2
                mx2 = n
            elif n < mx2 and n > mx3:
                mx3 = n
        return mx3 if mx3!=float('-inf') else max(nums)
                
# @lc code=end

s = Solution()
s.thirdMax([2,2,3,1]
)
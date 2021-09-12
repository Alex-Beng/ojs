#
# @lc app=leetcode.cn id=162 lang=python3
#
# [162] 寻找峰值
#

# @lc code=start
class Solution:
    def findPeakElement(self, nums: [int]) -> int:
        n = len(nums)
        L = 0
        R = n-1
        while L<R:
            m = (L+R)//2
            if nums[m] > nums[m+1]:
                R = m
            else:
                L = m+1
        return L
s = Solution()
res = s.findPeakElement(
    [1,2,3,1]
)
print(res)
# @lc code=end


#
# @lc app=leetcode.cn id=724 lang=python3
#
# [724] 寻找数组的中心下标
#

# @lc code=start
class Solution:
    def pivotIndex(self, nums: [int]) -> int:
        n = len(nums)
        ls = [0]*(n+1)
        for i in range(n):
            ls[i] = ls[i-1]+nums[i]
        for i in range(n):
            tl = ls[i-1]
            tr = ls[n-1]-ls[i]
            if tl==tr:
                return i
        return -1
# @lc code=end


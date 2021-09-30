#
# @lc app=leetcode.cn id=349 lang=python3
#
# [349] 两个数组的交集
#

# @lc code=start
class Solution:
    def intersection(self, nums1: [int], nums2: [int]) -> [int]:
        nums1 = set(nums1)
        nums2 = set(nums2)
        return list(nums1.intersection(nums2))
# @lc code=end


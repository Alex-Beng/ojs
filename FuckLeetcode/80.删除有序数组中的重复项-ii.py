#
# @lc app=leetcode.cn id=80 lang=python3
#
# [80] 删除有序数组中的重复项 II
#

# @lc code=start
class Solution:
    def removeDuplicates(self, nums: [int]) -> int:
        n = len(nums)
        ai = 0
        i = 0
        while i<n:
            tn = nums[i]
            j = i
            while j<n and nums[j]==tn:
                j += 1
            if j-i >= 2:
                # insert j-i
                for _ in range(2):
                    nums[ai] = tn
                    ai += 1
            else:
                # insert 1
                nums[ai] = tn
                ai += 1
            i = j
        return ai
# @lc code=end


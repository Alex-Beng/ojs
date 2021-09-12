#
# @lc app=leetcode.cn id=153 lang=python3
#
# [153] 寻找旋转排序数组中的最小值
#

# @lc code=start
class Solution:
    def findMin(self, nums: [int]) -> int:
        n = len(nums)
        L = 0
        R = n-1
        ans = nums[0]
        while L<=R:
            m = (L+R)//2
            # 无断点
            if nums[L] <= nums[R]:
                ans = min(nums[L], ans)
                break
            # 有断点
            else:
                if nums[m] >= nums[L]:
                    L = m+1
                else:
                    R = m-1
                    ans = min(nums[m], ans)
        return ans

# @lc code=end


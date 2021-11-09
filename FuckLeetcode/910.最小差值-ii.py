#
# @lc app=leetcode.cn id=910 lang=python3
#
# [910] 最小差值 II
#

# @lc code=start
class Solution:
    def smallestRangeII(self, nums: [int], k: int) -> int:
        nums.sort()
        ans = nums[-1]-nums[0]
        for i,n in enumerate(nums[:-1]):
            high = max(nums[-1]-k, n+k)
            low = min(nums[0]+k, nums[i+1]-k)
            ans = min(ans, high-low)
        return ans
# @lc code=end
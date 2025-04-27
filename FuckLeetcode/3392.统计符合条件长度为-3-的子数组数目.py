#
# @lc app=leetcode.cn id=3392 lang=python3
#
# [3392] 统计符合条件长度为 3 的子数组数目
#

# @lc code=start
class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        N = len(nums)
        nums2 = [n*2 for n in nums]
        res = 0
        for i in range(1, N-1):
            if nums2[i-1] + nums2[i+1] == nums[i]:
                res += 1
        return res
                
        
# @lc code=end


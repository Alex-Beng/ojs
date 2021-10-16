#
# @lc app=leetcode.cn id=287 lang=python3
#
# [287] 寻找重复数
#

# @lc code=start
class Solution:
    def findDuplicate(self, nums: [int]) -> int:
        n = len(nums)
        f = s = 0
        while True:
            s = nums[s]
            f = nums[f]
            f = nums[f]
            if s==f:
                break
        s = 0
        while s!=f:
            s = nums[s]
            f = nums[f]
        return s


# @lc code=end

s = Solution()
r = s.findDuplicate(
    # [1,3,4,2,1]
    [1,3,4,2,2]
    # [8,7,1,10,17,15,18,11,16,9,19,12,5,14,3,4,2,13,18,18]

)
print(r)


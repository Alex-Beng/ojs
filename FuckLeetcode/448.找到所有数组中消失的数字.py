#
# @lc app=leetcode.cn id=448 lang=python3
#
# [448] 找到所有数组中消失的数字
#

# @lc code=start
class Solution:
    def findDisappearedNumbers(self, nums: [int]) -> [int]:
        n = len(nums)
        nums = set(nums)
        ans = set(range(1,n+1)).difference(nums)
        return list(ans)
# @lc code=end

s = Solution()
r = s.findDisappearedNumbers(
    [4,3,2,7,8,2,3,1]
)
print(r)
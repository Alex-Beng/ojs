#
# @lc app=leetcode.cn id=303 lang=python3
#
# [303] 区域和检索 - 数组不可变
#

# @lc code=start
class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = nums
        n = len(nums)
        dp = [0]*(n+1)
        for i in range(n):
            dp[i] = dp[i-1] + nums[i]
        self.dp = dp

    def sumRange(self, left: int, right: int) -> int:
        return self.dp[right] - self.dp[left-1]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)
# @lc code=end


#
# @lc app=leetcode.cn id=384 lang=python3
#
# [384] 打乱数组
#

# @lc code=start
from random import random
class Solution:

    def __init__(self, nums: [int]):
        self.nums = nums

    def reset(self) -> [int]:
        return self.nums

    def shuffle(self) -> [int]:
        return sorted(self.nums, key=lambda k: random())



# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
# @lc code=end


#
# @lc app=leetcode.cn id=137 lang=python3
#
# [137] 只出现一次的数字 II
#

# @lc code=start
class Solution:
    def singleNumber(self, nums: [int]) -> int:
        n2times = dict()
        for n in nums:
            if n in n2times:
                n2times[n] += 1
            else:
                n2times[n] = 1
        return min(n2times, key=lambda k: n2times[k])
# @lc code=end


#
# @lc app=leetcode.cn id=260 lang=python3
#
# [260] 只出现一次的数字 III
#

# @lc code=start
class Solution:
    def singleNumber(self, nums: [int]) -> [int]:
        xor = 0
        for n in nums:
            xor ^= n
        lsb = xor&(-xor)
        l, r = 0,0
        for n in nums:
            if n&lsb:
                l ^= n
            else:
                r ^= n
        return [l, r]
# @lc code=end


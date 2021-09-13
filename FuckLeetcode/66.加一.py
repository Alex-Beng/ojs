#
# @lc app=leetcode.cn id=66 lang=python3
#
# [66] 加一
#

# @lc code=start
class Solution:
    def plusOne(self, digits: [int]) -> [int]:
        n = len(digits)
        carry_in = 1
        for i in range(n-1, -1, -1):
            digits[i] += carry_in
            carry_in = digits[i]//10
            digits[i] %= 10
            if not carry_in:
                break
        if carry_in:
            digits = [1] + digits
        return digits
# @lc code=end


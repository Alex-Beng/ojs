#
# @lc app=leetcode.cn id=423 lang=python3
#
# [423] 从英文中重建数字
#

# @lc code=start
class Solution:
    def originalDigits(self, s: str) -> str:
        vec = [0]*26
        nums = [0]*10
        for c in s:
            vec[ord(c)-ord('a')] += 1
        nums[0] = vec[-1]
        nums[2] = vec[-4]
        nums[4] = vec[ord('u')-ord('a')]
        nums[6] = vec[-3]

        nums[3] = vec[ord('r')-ord('a')] - nums[0] - nums[4]
        nums[5] = vec[ord('f')-ord('a')] - nums[4]
        nums[7] = vec[ord('v')-ord('a')] - nums[5]
        nums[1] = vec[ord('o')-ord('a')] - nums[0] - nums[2] - nums[4]
        nums[8] = vec[ord('h')-ord('a')] - nums[3]
        nums[9] = vec[ord('i')-ord('a')] - nums[6] - nums[5] - nums[8]
 
        return ''.join(str(i)*n for i,n in enumerate(nums))
# @lc code=end

'''
zero
two
six
four
three
five
seven
one
eight
nine
'''
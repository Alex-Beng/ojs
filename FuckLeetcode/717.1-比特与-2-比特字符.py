#
# @lc app=leetcode.cn id=717 lang=python3
#
# [717] 1比特与2比特字符
#

# @lc code=start
class Solution:
    def isOneBitCharacter(self, bits: [int]) -> bool:
        n = len(bits)
        i = 0
        while i<n:
            b = bits[i]
            if b==1:
                i += 2
            else:
                if i==n-1:
                    return True
                i += 1
        return False

# @lc code=end


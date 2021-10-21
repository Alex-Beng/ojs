#
# @lc app=leetcode.cn id=744 lang=python3
#
# [744] 寻找比目标字母大的最小字母
#

# @lc code=start
class Solution:
    def nextGreatestLetter(self, letters: [str], target: str) -> str:
        n = len(letters)
        L = 0
        R = n-1
        while L<=R:
            m = (L+R)//2
            mc = letters[m]
            if mc <= target:
                L = m+1
            else:
                R = m-1
        return letters[L%n]
# @lc code=end


#
# @lc app=leetcode.cn id=125 lang=python3
#
# [125] 验证回文串
#

# @lc code=start
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        n = len(s)
        l = 0
        r = n-1
        while l<r:
            cl = s[l]
            cr = s[r]
            if (ord(cl)<ord('a') or ord(cl)>ord('z')) and (ord(cl)<ord('0') or ord(cl)>ord('9')):
                l += 1
                continue
            if (ord(cr)<ord('a') or ord(cr)>ord('z')) and (ord(cr)<ord('0') or ord(cr)>ord('9')):
                r -= 1
                continue
            if cl != cr:
                return False
            l += 1
            r -= 1
        return True
            

# @lc code=end

s = Solution()
s.isPalindrome(
    "race a car"
)
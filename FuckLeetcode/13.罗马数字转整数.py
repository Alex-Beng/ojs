#
# @lc app=leetcode.cn id=13 lang=python3
#
# [13] 罗马数字转整数
#

# @lc code=start
class Solution:
    def romanToInt(self, s: str) -> int:
        s2n = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
        }

        n = len(s)
        ans = 0
        for i in range(n):
            if i+1<n and s2n[s[i]] < s2n[s[i+1]]:
                ans -= s2n[s[i]]
                
            else:
                ans += s2n[s[i]]
        return ans
# @lc code=end


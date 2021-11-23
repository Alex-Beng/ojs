#
# @lc app=leetcode.cn id=6 lang=python3
#
# [6] Z 字形变换
#

# @lc code=start
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        n = len(s)
        if numRows == 1:
            return s
        max_merge = (numRows-1)*2
        ans = ''
        for r in range(numRows):
            t_idx = r
            merge = max_merge - r*2
            while t_idx < n:
                ans += s[t_idx]
                if r!=0 and r!=numRows-1 and t_idx+merge<n:
                    ans += s[t_idx+merge]
                t_idx += max_merge
        return ans
# @lc code=end
s = Solution()
s.convert(
    "PAYPALISHIRING", 4
)
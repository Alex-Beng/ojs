#
# @lc app=leetcode.cn id=482 lang=python3
#
# [482] 密钥格式化
#

# @lc code=start
class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
        s = ''.join(s.split('-'))
        s = s.upper()
        n = len(s)
        flen = n%k
        ans = []
        if flen:
            ans.append(s[:flen])
        for i in range(flen, n, k):
            ans.append(s[i:i+k])
        return '-'.join(ans)
# @lc code=end


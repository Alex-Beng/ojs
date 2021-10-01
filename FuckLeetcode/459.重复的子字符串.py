#
# @lc app=leetcode.cn id=459 lang=python3
#
# [459] 重复的子字符串
#

# @lc code=start

class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)

        def valid(stripe: int):
            head = s[:stripe]
            for i in range(stripe, n, stripe):
                if s[i:i+stripe] != head:
                    return False
            return True
        
        stripe = 1
        while stripe*stripe <= n*n:
            if n%stripe==0 and n//stripe > 1:
                if valid(stripe):
                    return True
            stripe += 1
        return False
# @lc code=end
s = Solution()
s.repeatedSubstringPattern(
    # "aba"
    "abcabc"
)

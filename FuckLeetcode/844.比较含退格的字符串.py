#
# @lc app=leetcode.cn id=844 lang=python3
#
# [844] 比较含退格的字符串
#

# @lc code=start
class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        s = list(s)
        t = list(t)

        ls = len(s)
        lt = len(t)

        j = 0
        for i in range(ls):
            if s[i] == '#':
                j = max(j-1, 0)
            else:
                s[j] = s[i]
                j += 1
        s = ''.join(s[:j])
        j = 0
        for i in range(lt):
            if t[i] == '#':
                j = max(j-1, 0)
            else:
                t[j] = t[i]
                j += 1
        t = ''.join(t[:j])
        return s == t
        
# @lc code=end

s = Solution()
res = s.backspaceCompare(
    'ab#c', 'ad#c'
)
print(res)

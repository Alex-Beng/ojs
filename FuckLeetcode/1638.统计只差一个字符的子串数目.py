#
# @lc app=leetcode.cn id=1638 lang=python3
#
# [1638] 统计只差一个字符的子串数目
#

# @lc code=start
class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        # 枚举t的子串
        tsub2num = dict()
        lent = len(t)
        for beg in range(lent):
            for end in range(beg, lent):
                substr = t[beg:end+1]
                tsub2num[substr] = tsub2num.get(substr, 0) + 1
        # print(tsub2num)
        # 复杂度(n^2 x n x 27)
        # 枚举s子串，进行检查
        lens = len(s)
        ans = 0
        for beg in range(lens):
            for end in range(beg, lens):
                substr = list(s[beg:end+1])
                for i, c in enumerate(substr):
                    old_c = c
                    for t in range(0, 26):
                        new_c = chr(ord('a') + t)
                        # tring to change this 
                        if new_c != old_c:
                            substr[i] = new_c
                            
                            if ''.join(substr) in tsub2num:
                                ans += tsub2num[''.join(substr)]
                    substr[i] = old_c
        return ans

# @lc code=end
s = Solution()
r = s.countSubstrings(
    s = "aba", t = "baba"
)
print(r)
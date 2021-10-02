#
# @lc app=leetcode.cn id=500 lang=python3
#
# [500] 键盘行
#

# @lc code=start
class Solution:
    def findWords(self, words: [str]) -> [str]:
        fline = set("qwertyuiop")
        sline = set("asdfghjkl")
        tline = set("zxcvbnm")
        ans = []
        for wd in words:
            swd = set(wd.lower())
            if  swd.issubset(fline) or swd.issubset(sline) or swd.issubset(tline):
                ans.append(wd)
        return ans
# @lc code=end

s = Solution()
r = s.findWords(
    ["Hello","Alaska","Dad","Peace"]
)
print(r)
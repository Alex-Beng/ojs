#
# @lc app=leetcode.cn id=1249 lang=python3
#
# [1249] 移除无效的括号
#

# @lc code=start
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        s = list(s)
        sk = []
        dels = set()
        for idx,cha in enumerate(s):
            if cha == '(':
                sk.append((cha, idx))
            elif cha == ')':
                if len(sk) == 0:
                    # del it from s
                    # del s[idx]
                    dels.add(idx)
                else:
                    del sk[-1]
        for left in sk:
            dels.add(left[1])
        anss = []
        for i in range(len(s)):
            if i not in dels:
                anss.append(s[i])
        return ''.join(anss)
            
# @lc code=end


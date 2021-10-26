#
# @lc app=leetcode.cn id=301 lang=python3
#
# [301] 删除无效的括号
#

# @lc code=start
class Solution:
    def removeInvalidParentheses(self, s: str) -> [str]:
        sk = []
        for i,c in enumerate(s):
            if c=='(':
                sk.append(c)
            elif c==')':
                if len(sk) and sk[-1]=='(':
                    sk.pop()
                else:
                    sk.append(c)

        # left/right to be removed
        ltrm = 0
        rtrm = 0
        for c in sk:
            if c=='(':
                ltrm += 1
            else:
                rtrm += 1
        print(ltrm, rtrm)

        def valid(s: str):
            cnt = 0
            for i,c in enumerate(s):
                if c=='(':
                    cnt += 1
                elif c==')':
                    cnt -= 1
                if cnt<0:
                    return False
            return cnt==0

        s = list(s)
        ans = set()
        def dfs(s: [str], layer: int, ltrm: int, rtrm: int):
            nonlocal ans
            if layer==len(s):
                if valid(s):
                    ans.add(''.join(s))
                return
            c = s[layer]
            if c=='(' and ltrm>0:
                del s[layer]
                dfs(s, layer, ltrm-1, rtrm)
                s.insert(layer, c)
            if c==')' and rtrm>0:
                del s[layer]
                dfs(s, layer, ltrm, rtrm-1)
                s.insert(layer, c)
            dfs(s, layer+1, ltrm, rtrm)
            return
        dfs(s, 0, ltrm, rtrm)
        return list(ans)
# @lc code=end
#
# @lc app=leetcode.cn id=150 lang=python3
#
# [150] 逆波兰表达式求值
#

# @lc code=start
class Solution:
    def evalRPN(self, tokens: [str]) -> int:
        def comp(n1,n2,op):
            if op=='+':
                return n1+n2
            elif op=='-':
                return n1-n2
            elif op=='*':
                return n1*n2
            elif op=='/':
                return int(n1/n2)

        n_sk = []
        ops = {"+","-","*","/"}
        for tk in tokens:
            if tk in ops:
                n2 = n_sk.pop()
                n1 = n_sk.pop()
                n_sk.append(comp(n1,n2,tk))
            else:
                n_sk.append(int(tk))
            # print(n_sk)
        return n_sk[-1]

# @lc code=end


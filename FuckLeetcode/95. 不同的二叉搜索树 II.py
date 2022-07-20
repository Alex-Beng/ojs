from util import *

class Solution:
    def generateTrees(self, n: int) -> TreeNode:
        def gen(start: int, end: int):
            if start > end:
                return [None]
            if start == end:
                return [TreeNode(start)]
            t_ans = []
            for i in range(start, end+1):

                lefts = gen(start, i-1)
                righs = gen(i+1, end)

                for l in lefts:
                    for r in righs:
                        mid = TreeNode(i)
                        mid.left = l
                        mid.right = r
                        t_ans.append(mid)
            return t_ans
        return gen(1, n) if n else []

s = Solution()
t = s.generateTrees(0)
print(t)
for m in t:
    print(m.val)
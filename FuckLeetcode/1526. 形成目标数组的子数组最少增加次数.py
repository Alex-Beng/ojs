from typing import List

class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        stack = []
        ans = 0
        for i, n in enumerate(target):
            beedAdd = False
            while stack and stack[-1] >= n:
                t = stack.pop(-1)
                if not beedAdd:
                    ans += (t-n)
                    beedAdd = True
            stack.append(n)
            # print(stack, ans)
        if stack:
            ans += stack[-1]


        return ans

INPUT = [
    ([1,2,3,2,1], ),
    ([3,1,1,2], ),
    ([3,1,5,4,2], ),
    ([1,1,1,1], ), 
    ([3,4,2,5,6], )
]
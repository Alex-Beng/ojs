from typing import List

class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        n = len(pushed)
        sk = pushed[:1]
        cnt = 1
        for pn in popped:
            while cnt < n and (len(sk)==0 or sk[-1] != pn):
                sk.append(pushed[cnt])
                cnt += 1
            if len(sk) and sk[-1] == pn:
                del sk[-1]
        return len(sk)==0

s = Solution()
r = s.validateStackSequences(
    # pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
    # pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
    # [1,0], [1,0]
    [4,0,1,2,3], [4,2,3,0,1]
)
print(r)
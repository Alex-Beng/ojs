from typing import List

class Solution:
    def canSeePersonsCount(self, heights: List[int]) -> List[int]:
        # 从右到左遍历，维护一个单调栈
        n = len(heights)
        ans = [0]*n
        sk = []
        for i in range(n-1, -1, -1):
            h = heights[i]
            while len(sk) and h > heights[sk[-1]]:
                ans[i] += 1
                del sk[-1]
            if len(sk):
                ans[i] += 1
            sk.append(i)
        # print(ans)
        return ans
s = Solution()
s.canSeePersonsCount(
    # [10,6,8,5,11,9]
    [5,1,2,3,10]
)
from typing import List

class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        n = len(nums)
        # 维护一个单调递减的栈
        de_sk = []
        for i in range(n):
            if not len(de_sk) or nums[i] < nums[de_sk[-1]]:
                de_sk.append(i)
        ans = 0
        for i in range(n-1, -1, -1):
            while len(de_sk) and nums[de_sk[-1]] <= nums[i]:
                # print(de_sk[-1], i)
                ans = max(ans, i-de_sk[-1])
                del de_sk[-1]
        return ans
s = Solution()
r = s.maxWidthRamp(
    # [6,0,8,2,1,5]
    [9,8,1,0,1,9,4,0,4,1]
)
print(r)
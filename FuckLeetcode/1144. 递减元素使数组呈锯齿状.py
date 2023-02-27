from typing import List

class Solution:
    def movesToMakeZigzag(self, nums: List[int]) -> int:
        def help(pos: int) -> int:
            # SOME readable code
            res = 0
            for i in range(pos, len(nums), 2):
                a = 0
                if i - 1 >= 0:
                    a = max(a, nums[i] - nums[i - 1] + 1)
                if i + 1 < len(nums):
                    a = max(a, nums[i] - nums[i + 1] + 1)
                res += a
            return res

        n = len(nums)
        ans = 1e6 + 7
        tsum = 0
        # odd type
        for i in range(1, n, 2):
            if nums[i] >= nums[i-1] or (i+1 < n and nums[i] >= nums[i+1]):
                tsum += (nums[i] - min(nums[i-1], nums[i+1]) + 1) if i+1<n else (nums[i] - nums[i-1] + 1)
        ans = min(ans, tsum)
        tsum = 0
        # even type
        for i in range(0, n, 2):
            if i == 0:
                if i+1 < n and nums[i] >= nums[i+1]:
                    tsum += (nums[i] - nums[i+1] + 1)
            elif i == n-1:
                if nums[i] >= nums[i-1]:
                    tsum += (nums[i] - nums[i-1] + 1)
            elif nums[i] >= nums[i-1] or nums[i] >= nums[i+1]:
                # print(i)
                tsum += (nums[i] - min(nums[i-1], nums[i+1]) + 1)
        ans = min(ans, tsum)
        return ans
s = Solution()
r = s.movesToMakeZigzag(
    # [1,2,3]
    # [9,6,1,6,2]
    # [1,2,1,2]
    # [2,1,2,1]
    [1]
)
print(r)
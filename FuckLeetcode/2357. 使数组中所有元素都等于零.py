from typing import List

class Solution:
    # 乐
    def minimumOperations(self, nums: List[int]) -> int:
        return len(set(nums) - {0})
    def minimumOperations(self, nums: List[int]) -> int:
        nums.sort()
        accum = nums[0]
        n = len(nums)
        ans = 0 if accum == 0 else 1
        for i in range(1, n):
            num = nums[i]
            
            if num > accum:
                ans += 1
            accum = num
        return ans
s = Solution()
r = s.minimumOperations(
    [1,5,0,3,5]
)
print(r)
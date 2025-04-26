from functools import lru_cache

class Solution:
    def countSubarrays(self, nums: 'List[int]', minK: int, maxK: int) -> int:
        N = len(nums)
        
        res = 0
        lmin = lmax = -1
        L = -1
        for i in range(N):
            if nums[i] < minK or nums[i] > maxK:
                lmin = lmax = -1
                L = i
                continue
            if nums[i] == minK:
                lmin = i
            if nums[i] == maxK:
                lmax = i
            if lmin != -1 and lmax != -1:
                # print(min(lmin, lmax) - L, lmin, lmax, L, f"{i}/{nums[i]}")
                res += min(lmin, lmax) - L
        return res

s = Solution()
r = s.countSubarrays(
    [1,3,5,2,7,5], 1, 5
)
print(r)
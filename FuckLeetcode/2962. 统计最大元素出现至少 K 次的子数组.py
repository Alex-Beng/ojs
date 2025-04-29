class Solution:
    def countSubarrays(self, nums: 'List[int]', k: int) -> int:
        N = len(nums)
        maxn = max(nums)
        maxCnt = 0
        res = 0
        L = 0
        for n in nums:
            if n == maxn:
                maxCnt += 1
            while maxCnt == k:
                if nums[L] == maxn:
                    maxCnt -= 1
                L += 1
            res += L
        return res

s = Solution()
r = s.countSubarrays(
    [1,3,2,3,3], 2
)
print(r)
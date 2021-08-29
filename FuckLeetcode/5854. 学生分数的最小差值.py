class Solution:
    def minimumDifference(self, nums: [int], k: int) -> int:
        n = len(nums)
        nums.sort()
        ans = float('inf')
        for i in range(n):
            if i+k>n:
                break
            ans = min(ans, nums[i+k-1]-nums[i])
        print(ans)
        return ans
s = Solution()
s.minimumDifference(
    # [90],1
     [9,4,1,7],2
)
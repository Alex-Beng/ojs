class Solution:
    def searchInsert(self, nums: [int], target: int) -> int:
        n = len(nums)

        L = 0
        R = n-1
        ans = n
        while L<=R:
            m = (L+R)//2
            if target <= nums[m]:
                ans = m
                R = m-1
            else:
                L = m+1
        return ans
s = Solution()
s.searchInsert(
    # [1,3,5,6], 0
    [1,3,5,6], 7
)
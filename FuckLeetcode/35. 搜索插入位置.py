class Solution:
    def searchInsert(self, nums: [int], target: int) -> int:
        n = len(nums)

        L = 0
        R = n-1
        ans = n
        while L<=R:
            m = (L+R)//2
            if nums[m]<target:
                L = m+1
                ans = m
            else:
                R = m-1
        # if 
        return 0 if ans==n else ans+1
        print(ans, L, R)
        print(nums[ans])
s = Solution()
s.searchInsert(
    [1,3,5,6], 0
)
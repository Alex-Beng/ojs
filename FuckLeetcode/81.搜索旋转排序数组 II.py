class Solution:
    def search(self, nums: [int], target: int) -> bool:
        n = len(nums)
        if n==1:
            return nums[0]==target

        l = 0
        r = n-1
        while l<=r:
            m = (l+r)//2
            if nums[m]==target:
                return True
            # 特判
            if nums[m]==nums[l] and nums[m]==nums[r]:
                l += 1
                r -= 1
                continue

            if nums[l] <= nums[m]:
                if nums[l] <= target and target < nums[m]:
                    r = m-1
                else:
                    l = m+1
            else:
                if nums[m] < target and target <= nums[r]:
                    l = m+1
                else:
                    r = m-1
        return False

s = Solution()
s.search(
    # [1,0,1,1,1], 0
    # [1, 4], 4
    # [3,1], 1
    [1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1], 13
)
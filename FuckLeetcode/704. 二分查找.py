class Solution:
    def search(self, nums: [int], target: int) -> int:
        n = len(nums)
        L = 0
        R = n-1
        while L<=R:
            m = (L+R)//2
            if nums[m] < target:
                L = m+1
            elif nums[m] > target:
                R = m-1
            else:
                return m
        return -1
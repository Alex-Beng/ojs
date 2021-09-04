class Solution:
    def moveZeroes(self, nums: [int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        ptr = 0
        for i in range(n):
            if nums[i] != 0:
                nums[ptr] = nums[i]
                ptr += 1
        for i in range(ptr, n):
            nums[i] = 0
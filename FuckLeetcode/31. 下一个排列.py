class Solution:
    def nextPermutation(self, nums: [int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        ptr = n-1
        curr_min = nums[n-1]
        curr_min_idx = n-1

        while ptr>0:
            if nums[ptr-1] < nums[ptr]:
                # 从[ptr, n-1]寻找恰好比 nums[ptr-1] 大的数
                L = ptr
                R = n-1
                while L<=R:
                    print(L, R)
                    m = L + (R-L)//2
                    if nums[m] <= nums[ptr-1]:
                        R = m-1
                    elif nums[m] > nums[ptr-1]:
                        L = m+1
                        

                # print(L,R, nums)
                t = nums[ptr-1]
                nums[ptr-1] = nums[R]
                nums[R] = t
                break
            else:
                ptr -= 1
        # print(ptr, nums)
        nums[ptr:n] = sorted(nums[ptr:n])
        # print(ptr, nums)

s = Solution()
s.nextPermutation(
    # [3,2,1]
    # [1,1,5]
    # [1]
    # [2,4,3,1]
    # [2,3,1]
    [1,5,1]

)
            
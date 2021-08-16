class Solution:
    def search(self, nums: [int], target: int) -> int:
        n = len(nums)

        border = -1
        for i in range(0, n-1):
            if nums[i] > nums[i+1]:
                border = i+1
        nums = [(nums[i], i) for i in range(n)]

        if border == -1:
            pass
        else:
            nums = nums[border:] + nums[:border]
        # print(nums)
        L = 0
        R = n-1
        while L<=R:
            m = L+(R-L)//2
            if nums[m][0] > target:
                R = m-1
            elif nums[m][0] < target:
                L = m+1
            else:
                return nums[m][1]
        return -1
        # print(nums)
s = Solution()
print(s.search(
     [4,5,6,7,0,1,2], 0
    # [4,5,6,7,0,1,2], 3
    # [1],0
    # [4,5,6,7,0,1,2], 0
))

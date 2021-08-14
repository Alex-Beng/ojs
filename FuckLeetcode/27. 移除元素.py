class Solution:
    def removeElement(self, nums: [int], val: int) -> int:
        n = len(nums)

        l_pnt = 0
        r_pnt = 0
        
        while r_pnt < n:
            if nums[r_pnt]==val:
                r_pnt += 1
            else:
                nums[l_pnt] = nums[r_pnt]
                l_pnt += 1
                r_pnt += 1
        # print(nums[:l_pnt])
        return l_pnt
s = Solution()
print(s.removeElement(
    #  [3,2,2,3], 3
    # [0,1,2,2,3,0,4,2], 2
    [0], 0
))
        
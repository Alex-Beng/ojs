class Solution:
    def removeDuplicates(self, nums) -> int:
        n = len(nums)

        curr_pnt = 0
        next_pnt = 0
        while next_pnt < n:
            dup_num = nums[next_pnt]
            while next_pnt+1<n and nums[next_pnt+1]==nums[next_pnt]:
                next_pnt += 1
            
            nums[curr_pnt] = nums[next_pnt]
            curr_pnt += 1
            next_pnt += 1
        # print(nums[:curr_pnt])
        return curr_pnt
s = Solution()
s.removeDuplicates(
    # [1,1,2]
    [0,0,1,1,1,2,2,3,3,4]
)

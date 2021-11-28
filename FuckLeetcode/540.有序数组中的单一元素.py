class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        L = 0
        R = n-1
        while L<=R:
            m = (L+R)//2
            if m-1>=0 and nums[m-1]==nums[m]:
                if (m-1)%2==0: # 在右边
                    L = m+1
                else:
                    R = m-2
            elif m+1<n and nums[m+1]==nums[m]:
                if m%2==0:
                    L = m+2
                else:
                    R = m-1
            else: # sigle !
                return nums[m]
class Solution:
    def searchRange(self, nums: [int], target: int) -> [int]:
        n = len(nums)
        if not n:
            return [-1,-1]
        Lb = Rb = -1

        def valid(t):
            if t>=0 and t<n:
                return True
            else:
                return False

        L = 0
        R = n-1
        while L<=R:
            m = (L+R)//2
            if nums[m]>target:
                R = m-1
            elif  nums[m]<=target:
                L = m+1

        # print(L, R)
        if valid(L) and nums[L] == target:
            Rb = L
        if valid(R) and nums[R] == target:
            Rb = R
        L = 0
        R = n-1
        while L<=R:
            m = (L+R)//2
            if nums[m]>=target:
                R = m-1
            elif  nums[m]<target:
                L = m+1
        # print(L, R)
        if valid(L) and nums[L] == target:
            Lb = L
        if valid(R) and nums[R] == target:
            Lb = R
        return [Lb, Rb]
                

s = Solution()
print(s.searchRange(
     [5,7,7,8,8,10], 8
    # [1], 1
))
class Solution:
    def purchasePlans(self, nums: [int], target: int) -> int:
        n = len(nums)

        nums.sort()
        ans = 0

        for i in range(n):
            curr = nums[i]
            if curr >= target:
                break
            another = target-nums[i]
            L = i+1
            R = n-1
            ta = -1
            while L<=R:
                m = (L+R)//2
                if nums[m]<=another:
                    ta = m
                    L = m+1
                else:
                    R = m-1
            if ta>0:
                ans += (ta-i)
        return ans%1000000007
        
s = Solution()
print(s.purchasePlans(
    [2,2,1,9], 10
    #  [2,5,3,5], 6
))
            
        
        
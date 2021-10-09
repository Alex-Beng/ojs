class Solution:
    def firstMissingPositive(self, nums: [int]) -> int:
        nums = [i for i in nums if i>0]
        n = len(nums)
        if n==0:
            return 1
        if min(nums) > 1:
            return 1
        s = sum(nums)

        ns = n*(n+1)//2
        if ns==s:
            return n+1
        
        been = [0]*(n+1)
        for t in nums:
            if t>=1 and t<=n:
                been[t] = 1
        for i in range(1, n+1):
            if not been[i]:
                return i

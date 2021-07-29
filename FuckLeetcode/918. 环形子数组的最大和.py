class Solution:
    def maxSubarraySumCircular(self, nums) -> int:
        n = len(nums)

        is_neg = [1 if i<0 else 0 for i in nums]
        if sum(is_neg) == n:
            return max(nums)


        dp = [0]*n
        dp[0] = nums[0]
        for i in range(1, n):
            dp[i] = max(dp[i-1]+nums[i], nums[i])

        ans = max(dp)
        # print(ans)
        dp = [float('inf')]*n
        dp[0] = nums[0]
        for i in range(1, n):
            dp[i] = min(dp[i-1]+nums[i], nums[i])
        # print(min(dp))
        ans2 = sum(nums)-min(dp)
        
        return max(ans, ans2) 
s = Solution()
print(s.maxSubarraySumCircular([-10,-7,-9]))
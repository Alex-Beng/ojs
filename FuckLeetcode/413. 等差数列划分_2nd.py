class Solution:
    def numberOfArithmeticSlices(self, nums) -> int:
        n = len(nums)
        if n<3:
            return 0

        dp = [0]*(n)
        delta = nums[1]-nums[0]
        for i in range(2, n):
            if delta == nums[i]-nums[i-1]:
                dp[i] = dp[i-1]+1
            delta = nums[i]-nums[i-1]
        return sum(dp)
s = Solution()
print(s.numberOfArithmeticSlices(
    [1,]
))
class Solution:
    def findMaxConsecutiveOnes(self, nums: [int]) -> int:
        n = len(nums)
        dp = [[0,0] for _ in range(n)]
        dp[0][0] = nums[0]
        dp[0][1] = 0 if nums[0]!=0 else 1
        ans = max(dp[0])
        for i in range(1, n):
            if nums[i]==1:
                dp[i][0] = dp[i-1][0]+1
                dp[i][1] = dp[i-1][1]+1
            else:
                dp[i][0] = 0
                dp[i][1] = dp[i-1][0]+1
            ans = max(ans, max(dp[i]))
        print(dp)
        return ans
s = Solution()
print(s.findMaxConsecutiveOnes(
    [1,0,1,1,0,1]
))        
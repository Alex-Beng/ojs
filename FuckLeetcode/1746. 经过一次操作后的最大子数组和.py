class Solution:
    def maxSumAfterOperation(self, nums: [int]) -> int:
        n = len(nums)

        dp = [[0,0] for _ in range(n)]
        dp[0][0] = nums[0]
        dp[0][1] = nums[0]*nums[0]
        ans = max(dp[0])
        for i in range(1, n):
            dp[i][0] = max(nums[i], nums[i]+dp[i-1][0])
            dp[i][1] = max(dp[i-1][1]+nums[i], dp[i-1][0]+nums[i]*nums[i], nums[i]**2)
            ans = max(ans, max(dp[i]))

        # print(ans)
        return ans
s = Solution()
s.maxSumAfterOperation(
    # [2,-1,-4,-3]
    #  [1,-1,1,1,-1,-1,1]
    [-4,-49,-12,-75,-48,46,72,10,51,-51,26,-74,70,-1,-25,29,27]
)

print(sum([46,72,10,51,51*51,26]))
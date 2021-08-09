class Solution:
    def lengthOfLIS(self, nums) -> int:
        n = len(nums)

        dp = [0]*n
        ans = 1
        dp[0] = nums[0]

        for i in range(1, n):
            # print(dp, ans, nums[i])
            t_n = nums[i]
            
            l = 0
            r = ans
            while l<r:
                m = l + (r-l)//2
                if t_n > dp[m]:
                    l = m+1
                else:
                    r = m
            # print(l, r)
            dp[l] = t_n
            ans = max(ans, l+1)
        # print(ans)
        return ans
            
            
s = Solution()
s.lengthOfLIS(
    #  [10,9,2,5,3,7,101,18]
    # [0,1,0,3,2,3]
    [7,7,7,7,7,7,7]
)
class Solution:
    def minimumTotal(self, triangle) -> int:
        n = len(triangle)

        dp = [[float('-inf')]*(i+1) for i in range(n)]
        dp[0][0] = triangle[0][0]
        
        for i in range(1, n):
            for j in range(i+1):
                if j == 0:
                    dp[i][j] = dp[i-1][j]+triangle[i][j]
                elif j == i:
                    dp[i][j] = dp[i-1][j-1]+triangle[i][j]
                else:
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]
            # print(dp[i])
        return min(dp[n-1])
s = Solution()
print(s.minimumTotal(
    #  [[2],[3,4],[6,5,7],[4,1,8,3]]
    # [[-1],[-2,-3]]
    [[-1],[3,2],[-3,1,-1]]
))

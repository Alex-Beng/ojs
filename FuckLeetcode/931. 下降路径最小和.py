class Solution:
    def minFallingPathSum(self, matrix) -> int:
        n = len(matrix)
        dp = [[0]*n for i in range(n)]

        for i in range(n):
            dp[0][i] = matrix[0][i]
        
        for i in range(1, n):
            for j in range(0, n):
                dp[i][j] = min(dp[i-1][max(0,j-1):min(n,j+2)]) +matrix[i][j]
        return min(dp[n-1])
s = Solution()
print(s.minFallingPathSum(
    # [[2,1,3],[6,5,4],[7,8,9]]
    #  [[-19,57],[-40,-5]]
    # [[-48]]
    [[100,-42,-46,-41],[31,97,10,-10],[-58,-51,82,89],[51,81,69,-51]]
))


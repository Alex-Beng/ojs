class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        ns = len(s)
        nt = len(t)

        dp = [[0]*nt for _ in range(ns)]

        for i in range(ns):
            for j in range(nt):
                if s[i] == t[j]:
                    if j==0:
                        dp[i][j] = dp[i-1][j]+1
                    else:
                        dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j]
        # print(dp)
        return dp[-1][-1]
s = Solution()
s.numDistinct(
    # "rabbbit", "rabbit"
    "babgbag", "bag"
)
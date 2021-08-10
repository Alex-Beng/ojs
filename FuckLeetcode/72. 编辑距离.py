class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        L1 = len(word1)
        L2 = len(word2)
        dp = [[0]*(L1+1) for i in range(L2+1)]
        dp[0] = list(range(0, L1+1))
        for i in range(1, L2+1):
            dp[i][0] = i
        
        for i in range(1, L2+1):
            for j in range(1, L1+1):
                if word1[j-1] == word2[i-1]:
                    dp[i][j] = min(
                                   (min(dp[i-1][j], dp[i][j-1])+1), 
                                   dp[i-1][j-1]
                                )
                else:
                    dp[i][j] = min(
                                   dp[i][j-1]+1, # L1插
                                   dp[i-1][j]+1, # L1删
                                   dp[i-1][j-1]+1, # L1替换
                                )
        # print(dp)
        return dp[L2][L1]
s = Solution()
s.minDistance(
    # "horse", "ros"
    "intention", "execution"
)
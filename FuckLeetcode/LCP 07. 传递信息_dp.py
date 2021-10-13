class Solution:
    def numWays(self, n: int, relation: [[int]], k: int) -> int:
        able = [[0]*n for _ in range(n)]
        ins = [[] for _ in range(n)]

        for f,t in relation:
            able[f][t] = 1
            ins[t].append(f)

        dp = [[0]*n for _ in range(k)]
        dp[0] = able[0]
        for i in range(1,k):
            for j in range(n):
                for f in ins[j]:
                    dp[i][j] += dp[i-1][f]
        
        # print(dp)
        return dp[k-1][n-1]
s = Solution()
s.numWays(
    5, [[0,2],[2,1],[3,4],[2,3],[1,4],[2,0],[0,4]], 3
)

class Solution:
    def numSquares(self, n: int) -> int:
        # sq_map = {i*i for i in range(102)}
        # print(sq_map)
        dp = [i for i in range(n+1)]
        for i in range(2, n+1):
            # for sq in sq_map:
            for rt in range(1, i):
                sq = rt*rt
                if rt*rt > i:
                    break
                
                if i-sq>=0:
                    dp[i] = min(dp[i], dp[i-sq]+1)
        return dp[n]
                            
s = Solution()
print(s.numSquares(
    12
))
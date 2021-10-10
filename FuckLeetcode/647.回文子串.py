class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        dp = [[1 if r==c else 0 for c in range(n)] for r in range(n)]
        for l in range(2, n+1):
            for b in range(0, n-l+1):
                e = b+l-1
                if l==2:
                    dp[b][e] = 1 if s[b]==s[e] else 0
                else:
                    dp[b][e] = dp[b+1][e-1] if s[b]==s[e] else 0
        return sum([sum(r) for r in dp])

            
class Solution:
    def colorTheGrid(self, m: int, n: int) -> int:
        MOD = int(1e9+7)
        dp = [[0 for _ in range(n)] for _ in range(250)]
        validCol = []
        def dfs(d, s):
            if d == m:
                dp[s][0] = 1
                validCol.append(s)
                return
            for c in range(3):
                if c == s % 3 and d:
                    continue
                dfs(d+1, s*3 + c)
        dfs(0, 0)
        validFrom = {}
        for s in validCol:
            for ns in validCol:
                base = 1
                valid = True
                while base < int(3**m):
                    sn = s // base % 3
                    nsn = ns // base % 3
                    if sn == nsn:
                        valid = False
                        break
                    base *= 3
                if valid:
                    validFrom[ns] = validFrom.get(ns, [])
                    validFrom[ns].append(s)
                
        # print(validFrom)
        # print([a[:1] for a in dp])
        # print(validCol)
        for c in range(1, n):
            for s in validCol:
                for ps in validFrom.get(s, []):
                    dp[s][c] += dp[ps][c-1]
                    dp[s][c] %= MOD
                    
        res = 0
        for s in validCol:
            res += dp[s][n-1]
        return res % MOD
INPUT = [
    (5, 5)
]
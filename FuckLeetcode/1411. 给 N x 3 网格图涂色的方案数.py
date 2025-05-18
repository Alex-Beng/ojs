class Solution:
    def numOfWays(self, n: int) -> int:
        MOD = int(1e9+7)
        validRow = []
        def dfs(d, s):
            if d == 3:
                validRow.append(s)
                return
            for c in range(3):
                if c == s % 3 and d:
                    continue
                dfs(d+1, s*3 + c)
        # dfs(0, 0)
        validRow = [3, 5, 6, 7, 10, 11, 15, 16, 19, 20, 21, 23]
        validFrom = {}
        def init():
            for s in validRow:
                for ns in validRow:
                    base = 1
                    valid = True
                    while base < 27:
                        sn = s // base % 3
                        nsn = ns // base % 3
                        if sn == nsn:
                            valid = False
                            break
                        base *= 3
                    if valid:
                        validFrom[ns] = validFrom.get(ns, [])
                        validFrom[ns].append(s)
        # init()
        # print(validFrom)
        # exit()
        validFrom = {10: [3, 5, 6, 21, 23], 11: [3, 6, 7, 21], 16: [3, 5, 20, 21, 23], 19: [3, 5, 6, 15], 20: [3, 6, 7, 15, 16], 15: [5, 19, 20, 23], 23: [6, 7, 10, 15, 16], 21: [7, 10, 11, 16], 3: [10, 11, 16, 19, 20], 5: [10, 15, 16, 19], 6: [10, 11, 19, 20, 23], 7: [11, 20, 21, 
23]}
        
        dp = [[0] * 24 for _ in range(n)]
        for c in validRow:
            dp[0][c] = 1
        # print(dp[0])
        for r in range(1, n):
            for s in validRow:
                for ps in validFrom[s]:
                    dp[r][s] += dp[r-1][ps]
                    dp[r][s] %= MOD
            # print(dp[r])
        res = 0
        for s in validRow:
            res += dp[n-1][s]
        return res % MOD


        # print(len(validRow))

INPUT = [
    (1, ),
    (3, ),
    (7, ),
    (5000, )
]
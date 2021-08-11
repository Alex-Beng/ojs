class Solution:
    def change(self, amount: int, coins) -> int:
        dp = [0]*(amount+1)
        dp[0] = 1

        for c in coins:
            for i in range(c, amount+1):
                dp[i] += dp[i-c] 
            
        return dp[amount]
    
    def change(self, amount: int, coins) -> int:
        cn = len(coins)
        memo = dict()
        for i in range(1, cn+1):
            memo[(i, 0)] = 1

        def memo_search(k, amt):
            if k <= 0:
                return 0
            # print(k, amt)
            if amt<0:
                return 0

            if (k, amt) in memo:
                return memo[(k, amt)]

            memo[(k-1, amt)] = memo_search(k-1, amt)
            memo[(k, amt-coins[k-1])] = memo_search(k, amt-coins[k-1])
            memo[(k, amt)] = memo_search(k-1, amt) + memo_search(k, amt-coins[k-1])

            return memo[(k, amt)]
        return memo_search(cn, amount)

s = Solution()
print(s.change(
    # 5, [1,2,5]
    # 3, [2]
    10, [10]
))
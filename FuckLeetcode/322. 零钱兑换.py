class Solution:
    def coinChange(self, coins, amount: int) -> int:
        memo = dict()
        memo[0] = 0
        for c in coins:
            memo[c] = 1

        def memo_search(amt):
            if amt<0:
                return float('inf')
        
            if amt in memo:
                return memo[amt]
            
            ans = []
            for c in coins:
                t_ans = memo_search(amt-c)
                memo[amt-c] = t_ans
                ans.append(t_ans)
            return min(ans)+1
                
        ans = memo_search(amount)
        return ans if ans!=float('inf') else -1
    
s = Solution()
print(s.coinChange(
    # [1,2,5], 11
    # [2], 3
    [1], 2
))
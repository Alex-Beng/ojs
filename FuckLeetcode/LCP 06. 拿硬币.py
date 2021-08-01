class Solution:
    def minCount(self, coins) -> int:
        ans = 0
        for coin_heap in coins:
            # ans += coin_heap//2 + coin_heap%2
            ans += (coin_heap+1)//2
        return ans
s = Solution()
print(s.minCount(
    [4,2,1]
))
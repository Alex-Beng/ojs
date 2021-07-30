class Solution:
    def maxProfit(self, prices) -> int:
        n = len(prices)
        curr_low = prices[0]
        ans = -1
        for i in range(1, n):
            ans = max(ans, prices[i]-curr_low)
            curr_low = min(prices[i], curr_low)
        return ans if ans > 0 else 0

s = Solution()
print(s.maxProfit(
    [7,6,4,3,1]
    ))
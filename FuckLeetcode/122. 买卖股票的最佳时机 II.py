class Solution:
    def maxProfit(self, prices) -> int:
        n = len(prices)
        i,j = 0,0
        ans = 0
        while i < n:

            j = i
            while j<n-1:
                if prices[j+1]>=prices[j]:
                    j += 1
                else:
                    break
            ans += prices[j]-prices[i]
            i = j+1
        return ans

s = Solution()
print(s.maxProfit(
    # [7,1,5,3,6,4]
    # [1,2,3,4,5]
    [7,6,4,3,1]
))
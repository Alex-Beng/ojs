class Solution:
    def maxScoreSightseeingPair(self, values) -> int:
        n = len(values)
        curr_st = values[0]+0
        ans = float('-inf')
        for i in range(1, n):
            ans = max(curr_st+values[i]-i, ans)
            curr_st = max(curr_st, values[i]+i)
            
        return ans
s = Solution()
print(s.maxScoreSightseeingPair(
    [1,2,]
    ))
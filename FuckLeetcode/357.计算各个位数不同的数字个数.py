class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        dp = [0] * 10
        ans = [0] * 10
        dp[0] = 1
        dp[1] = 9
        ans[0] = 1
        ans[1] = 10
        for i in range(2, n+1):
            dp[i] = (10-i+1) * dp[i-1]
            ans[i] = ans[i-1] + dp[i]
        return ans[n]
INPUT = [
    (0, ),
    (2, ),

]
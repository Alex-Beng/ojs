class Solution:
    def largestAltitude(self, gain: [int]) -> int:
        n = len(gain)
        dp = [0]*(n+1)
        for i in range(1, n+1):
            dp[i] = dp[i-1]+gain[i-1]
        return max(dp)
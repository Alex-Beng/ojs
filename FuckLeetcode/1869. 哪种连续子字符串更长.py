class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        n = len(s)
        dp = [[0]*n for i in range(2)]
        dp[ord(s[0])-ord('0')][0] = 1
        for i in range(1, n):
            cha = s[i]
            tp = ord(cha)-ord('0')
            dp[tp][i] = dp[tp][i-1]+1
        return max(dp[0]) < max(dp[1])
s = Solution()
print(s.checkZeroOnes(
    # "1101"
    #  "111000"
    "110100010"
)
)


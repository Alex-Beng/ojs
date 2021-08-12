class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        n = len(s)
        dp = [[0]*n for i in range(2)]
        for i,cha in enumerate(s):
            tp = ord(cha)-ord('0')
            if i==0:
                dp[tp][0] = 1
                continue
            dp[tp][i] = dp[tp][i-1]+1
        return max(dp[0]) < max(dp[1])
s = Solution()
print(s.checkZeroOnes(
    # "1101"
    #  "111000"
    "110100010"
)
)


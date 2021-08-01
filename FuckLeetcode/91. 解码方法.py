class Solution:
    def __init__(self):
        self.num2word = dict()
        for i in range(ord('A'), ord('Z')+1): # 艹，我是傻逼
            self.num2word[str(i-ord('A')+1)] = chr(i)
        # print(self.num2word)
    def numDecodings(self, s: str) -> int:
        n = len(s)
        num2word = self.num2word
        if n == 1:
            if s[0] != '0':
                return 1
            else:
                return 0

        dp = [0]*(n+1)
        
        if s[:1] in num2word:
            dp[1] = 1
        if s[:2] in num2word:
            dp[2] = 1
        # print(dp)
        for i in range(n):
            if dp[i]:
                if i+1<=n and s[i:i+1] in num2word:
                    # print(num2word[s[i:i+1]], i, i+1)
                    dp[i+1] += dp[i]
                if i+2<=n and s[i:i+2] in num2word:
                    # print(num2word[s[i:i+2]])
                    dp[i+2] += dp[i]
        # print(dp)
        return dp[-1]
                
s = Solution()
print(s.numDecodings(
    # "12"
    "22"
))
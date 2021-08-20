class Solution:
    def longestValidParentheses(self, s: str) -> int:
        n = len(s)
        dp = [0 for i in range(n+1)]

        for i in range(n):
            if s[i]=='(':
                dp[i]=0
            else:
                if i-1>=0 and s[i-1]=='(':
                    dp[i] = 2
                    if i-2>=0:
                        dp[i] += dp[i-2]
                elif i-1>=0 and s[i-1]==')':
                    # print('cao', s[i-dp[i]-1>=0:])
                    if i-dp[i-1]-1>=0 and s[i-dp[i-1]-1]=='(':
                        # print('cao')
                        dp[i] = dp[i-1]+2
                        if i-dp[i-1]-2>=0:
                            dp[i] += dp[i-dp[i-1]-2]
                    else:
                        dp[i] = 0
                else:
                    dp[i] = 0
        # print(dp)
        return max(dp)
s = Solution()
s.longestValidParentheses(
    # "(()"
    # ")()())"
    "()((()))"
)
                    

        


class Solution:
    def wordBreak(self, s: str, wordDict) -> bool:
        n = len(s)

        wd_dict = dict()
        wd_len = dict()
        for wd in wordDict:
            wd_dict[wd] = 1
            tl = len(wd)
            if tl in wd_len:
                pass
            else:
                wd_len[tl] = 1

        wd_len = list(wd_len.keys())

        dp = [0]*(n+1)
        for l in wd_len:
            if s[:l] in wd_dict:
                dp[l] = 1
        # print(dp)
        for i in range(n):
            # print(dp)
            if dp[i]:
                for l in wd_len:
                    if i+l<=n and s[i:i+l] in wd_dict:
                        dp[i+l] = 1
        if dp[n]:
            return True
        else:
            return False

s = Solution()
print(s.wordBreak(
    # "applepenapple"
    "catsandog"
    ,  
    # ["apple", "pen"]
    ["cats", "dog", "sand", "and", "cat"]
    ))
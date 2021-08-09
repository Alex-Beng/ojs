class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[0]*n for i in range(n)]
        for i in range(n):
            dp[i][i] = 1
        
        # def is_pali(i, j):
        #     if (i, j) in memo:
        #         return memo[(i, j)]

        #     if s[i]==s[j]:
        #         if i+1 == j:
        #             memo[(i,j)] = 1
        #         else:
        #             memo[(i,j)] = memo[(i+1,j-1)] = is_pali(i+1, j-1)
        #     else:
        #         memo[(i,j)] = 0
        #     return memo[(i, j)]
        ans = -1
        ans_pair = (0,0)

        

        for ll in range(2, n+1):
            for b in range(0, n):
                
                e = b+ll-1
                if e >= n:
                    break
                if s[b] == s[e]:
                    if e-b < 3:
                        dp[b][e] = 1
                    else:
                        dp[b][e] = dp[b+1][e-1]
                else:
                    dp[b][e] = 0
                if dp[b][e] and (e-b+1) > ans:
                    ans = (e-b+1)
                    ans_pair = (b, e)
        # print(ans_pair)
        return s[ans_pair[0]:ans_pair[1]+1]
s = Solution()
print(s.longestPalindrome(
    # "babad"
    # "cbbd"
    # "a"
    "vmqjjfnxtyciixhceqyvibhdmivndvxyzzamcrtpywczjmvlodtqbpjayfchpisbiycczpgjdzezzprfyfwiujqbcubohvvyakxfmsyqkysbigwcslofikvurcbjxrccasvyflhwkzlrqowyijfxacvirmyuhtobbpadxvngydlyzudvnyrgnipnpztdyqledweguchivlwfctafeavejkqyxvfqsigjwodxoqeabnhfhuwzgqarehgmhgisqetrhuszoklbywqrtauvsinumhnrmfkbxffkijrbeefjmipocoeddjuemvqqjpzktxecolwzgpdseshzztnvljbntrbkealeemgkapikyleontpwmoltfwfnrtnxcwmvshepsahffekaemmeklzrpmjxjpwqhihkgvnqhysptomfeqsikvnyhnujcgokfddwsqjmqgsqwsggwhxyinfspgukkfowoxaxosmmogxephzhhy"
))

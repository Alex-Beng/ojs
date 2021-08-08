class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        memo = dict()
        def memo_search(i, j):
            if i>j:
                memo[(i, j)] = 0
                return 0
            elif i==j:
                memo[(i, j)] = 1
                return 1
            
            if (i, j) in memo:
                return memo[(i, j)]
            
            if s[i]==s[j]:
                t_res = memo_search(i+1, j-1)
                memo[(i+1, j-1)] = t_res
                memo[(i, j)] = t_res+2
            else:
                t_res = memo_search(i+1, j)
                memo[(i+1, j)] = t_res
                t_res = memo_search(i, j-1)
                memo[(i, j-1)] = t_res
                memo[(i, j)] = max(memo[(i+1, j)], memo[(i, j-1)])
            return memo[(i, j)]
        memo_search(0, n-1)
        return max([memo[k] for k in memo.keys()])

s = Solution()
print(s.longestPalindromeSubseq(
    # "bbbab"
    # "cbbd"
    "a"
))
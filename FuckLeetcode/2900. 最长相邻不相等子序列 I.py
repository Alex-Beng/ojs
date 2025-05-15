from typing import List

class Solution:
    def getLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        N = len(words)
        pre = list(range(N))
        dp = [1] * N
        maxdp = 0
        maxi = 0
        for i in range(1, N):
            for j in range(i):
                if groups[j] != groups[i] and dp[j] + 1 > dp[i]:
                    pre[i] = j
                    dp[i] = dp[j] + 1
                    if dp[i] > maxdp:
                        maxdp = dp[i]
                        maxi = i
        # print(maxdp)
        ti = maxi
        res = []
        while pre[ti] != ti:
            res.append(words[ti])
            ti = pre[ti]
        res.append(words[ti])
        return res[::-1]
INPUT = [
    (["e","a","b"], [0,0,1])
]
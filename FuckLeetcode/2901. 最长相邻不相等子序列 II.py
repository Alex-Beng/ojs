from typing import List

class Solution:
    def getWordsInLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        N = len(words)
        pre = list(range(N))
        dp = [1] * N
        maxdp = 0
        maxi = 0

        def checkDist(a, b):
            if len(a) != len(b):
                return False
            err = 0
            for i in range(len(a)):
                if a[i] != b[i]:
                    err += 1
                if err > 1:
                    return False
            return err == 1

        for i in range(1, N):
            for j in range(i):
                if groups[j] != groups[i] and checkDist(words[i], words[j]) and  dp[j] + 1 > dp[i]:
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
    (["bab","dab","cab"], [1,2,2]),
    (["a","b","c","d"], [1,2,3,4])
]
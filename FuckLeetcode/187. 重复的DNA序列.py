class Solution:
    def findRepeatedDnaSequences(self, s: str) -> [str]:

        n = len(s)
        word2times = dict()
        for tail in range(9, n):
            head = tail-9
            ts = s[head:tail+1]
            if ts in word2times:
                word2times[ts] += 1
            else:
                word2times[ts] = 1
        # print(word2times)
        ans = []
        for wd in word2times:
            if word2times[wd] > 1:
                ans.append(wd)
        return ans
            
s = Solution()
s.findRepeatedDnaSequences(
    "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
)
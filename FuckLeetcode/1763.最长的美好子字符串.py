class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        n = len(s)
        lgt_len = 0
        lgt_i, lgt_j = 0, 0
        for i in range(n):
            for j in range(i+1, n+1):
                ts = set(s[i:j])
                valid = True
                for k in ts:
                    if chr(ord(k)^32) not in ts:
                        valid = False
                if valid and j-i > lgt_len:
                    lgt_i, lgt_j = i, j
                    lgt_len = j-i
                    print(i, j, s[i:j])

                        
        return s[lgt_i:lgt_j]

from functools import lru_cache

class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        @lru_cache(None)
        def dp(i, j, n):
            # s1[i:i+n] -> s2[j:j+n] 是否可由扰乱得到
            if n==1:
                return s1[i] == s2[j]
            elif n==2:
                return s1[i:i+n] == s2[j:j+n] or s1[i:i+n][::-1] == s2[j:j+n]
            
            for len1 in range(1, n):
                len2 = n-len1
                if dp(i, j, len1) and dp(i+len1, j+len1, len2) or \
                    dp(i, j+len2, len1) and dp(i+len1, j, len2):
                    return True
            return False
        return dp(0, 0, len(s1))


s = Solution()
r = s.isScramble(
    # "great", "rgeat"
    "abcde", "caebd"
)
print(r)
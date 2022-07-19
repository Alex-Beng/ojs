from functools import lru_cache

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        @lru_cache(None)
        def dp(n1, n2, n):
            print(n1, n2, n)
            if n==0:
                return n1==0 and n2==0
            elif n==1:
                return n1==1 and n2==0 and s1[0] == s3[0] or \
                    n2==1 and n1==0 and s2[0] == s3[0]
            
            if n1==0:
                return s2[:n2] == s3[:n]
            elif n2==0:
                return s1[:n1] == s3[:n]
            
            if s1[n1-1] != s3[n-1] and s2[n2-1] != s3[n-1]:
                return False

            t_ans = dp(n1-1, n2, n-1) if s1[n1-1]==s3[n-1] else False
            t_ans = t_ans or dp(n1, n2-1, n-1) if s2[n2-1]==s3[n-1] else t_ans

            return t_ans
        return dp(len(s1), len(s2), len(s3))
s = Solution()
t = s.isInterleave(
    # "aabcc",
    # "dbbca",
    # "aadbbcbcac"
    # "aa", "ab", "abaa"
    "ab", "bc", "bbac"
)
print(t)
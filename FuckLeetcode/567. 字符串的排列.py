from functools import lru_cache
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        @lru_cache(None)
        def idx(cha):
            return ord(cha)-ord('a')
        if s1 == s2:
            return True
        s1_vec = [0]*26
        for cha in s1:
            s1_vec[idx(cha)] += 1
        s1_vec = tuple(s1_vec)
        n = len(s2)
        dp = [[0]*26 for _ in range(n)]
        dp[0][idx(s2[0])] = 1

        for i in range(n):
            for j in range(26):
                dp[i][j] = dp[i-1][j]
            dp[i][idx(s2[i])] += 1

        dp_times = dict()
        dp_times[tuple([0]*26)] = 1

        for j in range(n):
            dpj = dp[j]
            dpi = [0]*26
            for k in range(26):
                dpi[k] = dpj[k] - s1_vec[k]
            if tuple(dpi) in dp_times:
                return True

            dp_times[tuple(dpj)] = 1
        return False
s = Solution()
print(s.checkInclusion(
    # "ab", "eidbxaooo"
    "a", "a"
))
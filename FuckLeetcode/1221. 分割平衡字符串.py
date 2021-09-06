class Solution:
    def balancedStringSplit(self, s: str) -> int:
        sk = []
        ans = 0
        for i,c in enumerate(s):
            # print(i, sk)
            if len(sk)==0:
                ans += 1
                sk.append(c)
            else:
                if sk[-1] == c:
                    sk.append(c)
                else:
                    del sk[-1]
        return ans
s = Solution()
print(s.balancedStringSplit(
    "RLRRLLRLRL"
))

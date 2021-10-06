class Solution:
    def validPalindrome(self, s: str) -> bool:
        def able(s: str, cand: bool):
            n = len(s)
            l = 0
            r = n-1
            while l<r:
                lc = s[l]
                rc = s[r]
                if lc==rc:
                    l += 1
                    r -= 1
                else:
                    if cand:
                        return able(s[l+1:r+1], False) or able(s[l:r], False)
                    else:
                        return False
            return True
        return able(s, True)
s = Solution()
print(s.validPalindrome("aba"))
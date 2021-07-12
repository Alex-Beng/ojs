class Solution:
    def reverseLeftWords(self, s: str, n: int) -> str:
        return s[n:] + s[:n]

s = Solution()
a = s.reverseLeftWords("lrloseumgh", 2)
print(a)

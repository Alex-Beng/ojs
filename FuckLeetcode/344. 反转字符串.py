class Solution:
    def reverseString(self, s) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        n = len(s)
        for i in range(n//2):
            s[i], s[n-i-1] = s[n-i-1], s[i]

s = Solution()
a = ["h","e","l","l","o", 'y']
s.reverseString(
    a
)
print(a)
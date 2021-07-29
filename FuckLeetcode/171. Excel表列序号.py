class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        n = len(columnTitle)
        columnTitle = list(columnTitle)
        curr_base = 1
        ans = 0
        for i in range(n-1, -1, -1):
            curr_bit = ord(columnTitle[i])-ord('A')+1
            ans += curr_bit*curr_base
            curr_base *= 26
        return ans
s = Solution()
print(s.titleToNumber("ZY"))

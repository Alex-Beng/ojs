class Solution:
    def checkRecord(self, s: str) -> bool:
        return not 'LLL' in s and sum([1 if cha=='A' else 0 for cha in s])<2

s = Solution()
print(s.checkRecord(
    # "PPALLP"
    "PPALLL"
))
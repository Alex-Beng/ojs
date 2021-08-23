class Solution:
    def __init__(self):
        self.map = dict()
        for i in range(32, 127):
            self.map[chr(i)] = chr(i)
        for i in range(ord('A'), ord('Z')+1):
            self.map[chr(i)] = chr( ord('a') + (i-ord('A')) )

    def toLowerCase(self, s: str) -> str:
        return ''.join([self.map[cha] for cha in s])
s = Solution()
print(s.toLowerCase(
    "FUCKY*&*OU"
))
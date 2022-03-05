import re

class Solution:
    def isNumber(self, s: str) -> bool:

        return re.fullmatch('[+-]?(([0-9]+\.)|([0-9]*\.[0-9]+)|[0-9]+)([eE][+-]?[0-9]+)?', s) is not None

s = Solution()

ss = ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]
for ts in ss:
    print(s.isNumber(ts), ts)

ss = ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]
for ts in ss:
    print(s.isNumber(ts), ts)


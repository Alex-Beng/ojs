from collections import Counter
class Solution:
    def maxDifference(self, s: str) -> int:
        c2n = Counter(s)
        odds = [n for n in c2n.values() if n&1]
        evens = [n for n in c2n.values() if not n&1]

        return max(odds)-min(evens)
INPUT = [
    ('tzt', )
]
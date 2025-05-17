class Solution:
    def minDeletion(self, s: str, k: int) -> int:
        c2t = {}
        for c in s:
            c2t[c] = c2t.get(c, 0) + 1
        cs = sorted(c2t.keys(), key=lambda k: c2t[k], reverse=True)[k:]
        res = 0
        for c in cs:
            res += c2t[c]
        return res
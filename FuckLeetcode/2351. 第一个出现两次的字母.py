class Solution:
    def repeatedCharacter(self, s: str) -> str:
        c2times = {}
        for c in s:
            if c in c2times:
                return c
            c2times[c] = 1
        return ""
INPUT = [
    ("abccbaacz",)
]
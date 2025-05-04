class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        if len(typed) < len(name):
            return False
        if typed == name:
            return True
        N = len(name)
        M = len(typed)
        L = 0
        R = 0
        while L < N and R < M:
            if name[L] != typed[R]:
                return False
            if L + 1 < N and name[L+1] == name[L]:
                L += 1
                R += 1
            else:
                while R + 1 < M and typed[R+1] == typed[R]:
                    R += 1
                L += 1
                R += 1
        return R == M and L == N
INPUT = [
    ("alex", "aaleex"),
    ("saeed", "ssaaedd"),
    ("alex", "aaleexa"),
    ("pyplrz", "ppyypllr")
]
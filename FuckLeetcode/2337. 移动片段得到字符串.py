class Solution:
    def canChange(self, start: str, target: str) -> bool:
        if len(start) != len(target):
            return False
        sStart = tuple(c for c in start if c != '_')
        sTarget = tuple(c for c in target if c != '_')
        if sStart != sTarget:
            return False
        iStart = tuple(i for i in range(len(start)) if start[i] != '_')
        iTarget = tuple(i for i in range(len(target)) if target[i] != '_')
        for i in range(len(iStart)):
            si = iStart[i]
            ti = iTarget[i]
            c = start[si]
            if c == 'R' and si > ti \
            or c == 'L' and si < ti:
                return False
        return True
INPUT = [
    ("_L__R__R_", "L______RR"),
    ("R_L_", "__LR"),
    ("_R", "R_")
]

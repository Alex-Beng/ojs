class Solution:
    def judgeCircle(self, moves: str) -> bool:
        usk = 0
        lsk = 0
        for m in moves:
            if m=='U':
                usk += 1
            elif m=='D':
                usk -= 1
            elif m=='L':
                lsk += 1
            elif m=='R':
                lsk -= 1
        return usk==0 and lsk==0
class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        i = 0
        j = 0
        n = len(start)
        m = len(end)
        if n != m:
            return False
        while i < n and j < m:
            while i + 1 < n and start[i] == 'X':
                i += 1
            while j + 1 < m and end[j] == 'X':
                j += 1
            # print(i, j)
            if start[i] != end[j]:
                return False
            if start[i] == 'R' and i > j or \
            start[i] == 'L' and i < j:
                return False
            i += 1
            j += 1
        while i < n:
            if start[i] != 'X':
                return False
            i += 1
        while j < m:
            if end[j] != 'X':
                return False
            j += 1

        return True
INPUT = [
    ("RXXLRXRXL", "XRLXXRRLX"),
    ("X", "L")
]

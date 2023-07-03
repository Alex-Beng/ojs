from functools import lru_cache

class Solution:
    def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
        table = dict()
        for row in matrix:
            t = tuple(row) if row[0] == 0 else tuple(1-n for n in row)
            table[t] = table.get(t, 0) + 1
        return max(table.values())
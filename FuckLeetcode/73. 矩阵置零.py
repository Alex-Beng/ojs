class Solution:
    def setZeroes(self, matrix: [[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        cols = set()
        rows = set()
        row = len(matrix)
        col = len(matrix[0])
        for r in range(row):
            for c in range(col):
                if matrix[r][c] == 0:
                    # print(r, c)
                    cols.add(c)
                    rows.add(r)
        # print(rows, cols)
        for r in rows:
            for c in range(col):
                matrix[r][c] = 0
        for c in cols:
            for r in range(row):
                matrix[r][c] = 0
s = Solution()
s.setZeroes(
    [[0,1,2,0],
    [3,4,5,2],
    [1,3,1,5]]
)
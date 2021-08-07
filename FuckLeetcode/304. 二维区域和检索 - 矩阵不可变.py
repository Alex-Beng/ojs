class NumMatrix:

    def __init__(self, matrix):
        self.row = len(matrix)
        self.col = len(matrix[0])
        self.integer_mat = [[0]*(self.col+1) for r in range(self.row+1)]

        for r in range(1, self.row+1):
            for c in range(1, self.col+1):
                self.integer_mat[r][c] = self.integer_mat[r-1][c] + self.integer_mat[r][c-1] \
                                       - self.integer_mat[r-1][c-1] + matrix[r-1][c-1]
        # print(self.integer_mat)
    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        row2 += 1
        col2 += 1
        return self.integer_mat[row2][col2] - self.integer_mat[row2][col1] \
             - self.integer_mat[row1][col2] + self.integer_mat[row1][col1]



# Your NumMatrix object will be instantiated and called as such:
matrix =  [ [3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]

obj = NumMatrix(matrix)

ya = [[2,1,4,3],[1,1,2,2],[1,2,2,4]]

for param in ya:
    row1, col1, row2, col2 = param
    param_1 = obj.sumRegion(row1,col1,row2,col2)
    print(param_1)
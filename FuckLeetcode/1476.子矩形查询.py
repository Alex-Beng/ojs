class SubrectangleQueries:

    def __init__(self, rectangle):
        self.rectangle = rectangle

    def updateSubrectangle(self, row1: int, col1: int, row2: int, col2: int, newValue: int) -> None:
        for r in range(row1, row2+1):
            for c in range(col1, col2+1):
                self.rectangle[r][c] = newValue

    def getValue(self, row: int, col: int) -> int:
        return self.rectangle[row][col]



# Your SubrectangleQueries object will be instantiated and called as such:
rectangle = [[1,2,1],
             [4,3,4],
             [3,2,1],
             [1,1,1]]

obj = SubrectangleQueries(rectangle)
obj.updateSubrectangle(0,0,2,2,5)
print(rectangle)
param_2 = obj.getValue(1,1)
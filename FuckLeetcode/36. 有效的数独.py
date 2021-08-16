class Solution:
    def isValidSudoku(self, board:[[str]]) -> bool:
        def check(r, c, cha):
            for i in range(9):
                if i==r:
                    continue
                if board[i][c] == cha:
                    return False
            for j in range(9):
                if j==c:
                    continue
                if board[r][j] == cha:
                    return False
            big_r, big_c = r//3*3, c//3*3
            for i in range(big_r, big_r+3):
                for j in range(big_c, big_c+3):
                    if i==r and j==c:
                        continue
                    if board[i][j] == cha:
                        return False
            return True


        for r in range(9):
            for c in range(9):
                if board[r][c]=='.':
                    continue
                if not check(r, c, board[r][c]):
                    print(r, c)
                    return False
        return True
s = Solution()
print(s.isValidSudoku(
    [["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]

))
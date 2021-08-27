class Solution:
    def exist(self, board: [[str]], word: str) -> bool:
        row = len(board)
        col = len(board[0])

        delta = [[0, 1],
                 [0, -1],
                 [1, 0],
                 [-1, 0]]
        def dfs(c_row, c_col, p_str, been):
            if p_str == '':
                return True

            for i in range(len(delta)):
                n_row = c_row + delta[i][0]
                n_col = c_col + delta[i][1]
                if n_row<0 or n_row>=row or n_col<0 or n_col>=col:
                    continue
                if board[n_row][n_col] == p_str[0] and not been[n_row][n_col]:
                    been[n_row][n_col] = 1
                    if dfs(n_row, n_col, p_str[1:], been):
                        return True
                    else:
                        been[n_row][n_col] = 0
            return False
        
        for r in range(row):
            for c in range(col):
                if board[r][c] == word[0]:
                    been = [[0]*col for _ in range(row)]
                    been[r][c] = 1
                    if dfs(r, c, word[1:], been):
                        return True
        return False
s = Solution()
print(s.exist(
    #  [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], 'SEE'
    # [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "ABCCED"
    # [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "ABCB"
    [["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]],"ABCESEEEFS"
))
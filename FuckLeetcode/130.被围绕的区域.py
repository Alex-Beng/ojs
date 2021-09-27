#
# @lc app=leetcode.cn id=130 lang=python3
#
# [130] 被围绕的区域
#

# @lc code=start
from queue import Queue
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        row = len(board)
        col = len(board[0])

        dr = [0,0,1,-1]
        dc = [1,-1,0,0]
        def bfs(r,c,org,bec):
            q = Queue()
            q.put((r,c))
            board[r][c] = bec
            while not q.empty():
                r,c = q.get()
                for i in range(4):
                    nr = r+dr[i]
                    nc = c+dc[i]
                    if nr>=0 and nr<row and nc>=0 and nc<col \
                        and board[nr][nc]==org:
                        board[nr][nc] = bec
                        q.put((nr,nc))
        for i in range(col):
            if board[0][i] == 'O':
                bfs(0, i, 'O', '#')
        for i in range(1, row):
            if board[i][col-1] == 'O':
                bfs(i, col-1, 'O', '#')
        for i in range(0, col-1):
            if board[row-1][i] == 'O':
                bfs(row-1, i, 'O', '#')
        for i in range(1, row-1):
            if board[i][0] == 'O':
                bfs(i, 0, 'O', '#')

        for i in range(1, row-1):
            for j in range(1, col-1):
                if board[i][j] == 'O':
                    bfs(i, j, 'O', 'X')

        for i in range(col):
            if board[0][i] == '#':
                bfs(0, i, '#', 'O')
        for i in range(1, row):
            if board[i][col-1] == '#':
                bfs(i, col-1, '#', 'O')
        for i in range(0, col-1):
            if board[row-1][i] == '#':
                bfs(row-1, i, '#', 'O')
        for i in range(1, row-1):
            if board[i][0] == '#':
                bfs(i, 0, '#', 'O')

# @lc code=end


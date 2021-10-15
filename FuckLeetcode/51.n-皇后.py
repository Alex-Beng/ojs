#
# @lc app=leetcode.cn id=51 lang=python3
#
# [51] N 皇后
#

# @lc code=start
class Solution:
    def solveNQueens(self, n: int) -> [[str]]:
        def valid(i, j):
            for r in range(i-1, -1, -1):
                c = j
                if board[r][c]=='Q':
                    return False
                c = j - (i-r)
                if c>=0 and board[r][c]=='Q':
                    return False
                c = j + (i-r)
                if c<n and board[r][c]=='Q':
                    return False
            return True
        board = [['.']*n for _ in range(n)]
        ans = []
        def dfs(layer: int):
            if layer == n:
                ans.append([''.join(r) for r in board])
                return
            for c in range(n):
                if valid(layer, c):
                    board[layer][c] = 'Q'
                    dfs(layer+1)
                    board[layer][c] = '.'
        dfs(0)
        return ans
                
# @lc code=end
s = Solution()
r = s.solveNQueens(
    9
)

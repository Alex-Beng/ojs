#
# @lc app=leetcode.cn id=52 lang=python3
#
# [52] N皇后 II
#

# @lc code=start
class Solution:
    def totalNQueens(self, n: int) -> [[str]]:
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
        ans = 0
        def dfs(layer: int):
            nonlocal ans
            if layer == n:
                ans += 1
                return
            for c in range(n):
                if valid(layer, c):
                    board[layer][c] = 'Q'
                    dfs(layer+1)
                    board[layer][c] = '.'
        dfs(0)
        return ans
# @lc code=end


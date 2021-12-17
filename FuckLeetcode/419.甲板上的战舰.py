class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        m = len(board)
        n = len(board[0])
        been = [[0]*n for _ in range(m)]
        def dfs(r, c):
            been[r][c] = 1
            if r+1<m and board[r+1][c]=='X':
                dfs(r+1, c)
            elif c+1<n and board[r][c+1]=='X':
                dfs(r, c+1)
            else:
                return

        ans = 0
        for r in range(m):
            for c in range(n):
                if board[r][c]=='X' and not been[r][c]:
                    dfs(r, c)
                    ans += 1
        return ans

    def countBattleships(self, board: List[List[str]]) -> int:
        m = len(board)
        n = len(board[0])
        ans = 0
        # 只要满足“左上角”是起点就行
        for r in range(m):
            for c in range(n):
                if board[r][c]=='X' and \
                    (r-1>=0 and board[r-1][c]=='.' or r==0) and \
                    (c-1>=0 and board[r][c-1]=='.' or c==0):
                    ans += 1
        return ans
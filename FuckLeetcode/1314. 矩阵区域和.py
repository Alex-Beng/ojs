class Solution:
    def matrixBlockSum(self, mat, k: int):
        m = len(mat)
        n = len(mat[0])

        integer_mat = [[0]*(n+1) for r in range(m+1)]

        for r in range(1, m+1):
            for c in range(1, n+1):
                integer_mat[r][c] = integer_mat[r-1][c] + integer_mat[r][c-1] - integer_mat[r-1][c-1] + mat[r-1][c-1]
        ans = [[0]*n for r in range(m)]
        for r in range(m):
            for c in range(n):
                r_min = max(0, r-k)
                r_max = min(m, r+k+1)
                c_min = max(0, c-k)
                c_max = min(n, c+k+1)
                
                ans[r][c] = integer_mat[r_max][c_max] - integer_mat[r_min][c_max] - integer_mat[r_max][c_min] + integer_mat[r_min][c_min]
        return ans
s = Solution()
print(s.matrixBlockSum(
    [[1,2,3],[4,5,6],[7,8,9]], 2
))
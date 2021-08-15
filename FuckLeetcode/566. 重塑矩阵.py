class Solution:
    def matrixReshape(self, mat: [[int]], r: int, c: int) -> [[int]]:
        def num_stream(mat):
            r = len(mat)
            c = len(mat[0])
            for i in range(r):
                for j in range(c):
                    yield mat[i][j]
        r_r = len(mat)
        r_c = len(mat[0])
        if r_r*r_c != r*c:
            return mat
        mat_gen = num_stream(mat)
        ans = [[0]*c for i in range(r)]
        for i in range(r):
            for j in range(c):
                ans[i][j] = next(mat_gen)
        # print(ans)
        return ans
s = Solution()
print(s.matrixReshape(
    #  [[1,2],[3,4]], 1,4
    [[1,2],[3,4]],2,4
))
        
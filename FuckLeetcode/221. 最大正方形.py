class Solution:
    def maximalSquare(self, matrix) -> int:
        row = len(matrix)
        col = len(matrix[0])
        # for r in range(row):
        #     for c in range(col):
        #         matrix[r][c] = int(matrix[r][c])

        # integer_mat = [[0]*(col+1) for r in range(row+1)]
        # for r in range(1, row+1):
        #     for c in range(1, col+1):
        #         integer_mat[r][c] = integer_mat[r-1][c] + integer_mat[r][c-1] \
        #                           - integer_mat[r-1][c-1] + matrix[r-1][c-1]
        
        # def get_sum(r_min, r_max, c_min, c_max):
        #     return integer_mat[r_max+1][c_max+1] - integer_mat[r_max+1][c_min] \
        #          - integer_mat[r_min][c_max+1] + integer_mat[r_min][c_min]

        dp = [[0]*col for r in range(row)]
        for r in range(row):
            for c in range(col):
                if r==0 or c==0:
                    dp[r][c] = int(matrix[r][c])
                    continue
                
                if matrix[r][c] == '1':
                    # t_val = dp[r-1][c-1]
                    # if t_val != 0:
                    #     for t in range(1, t_val+1):
                    #         if get_sum(r-t, r, c-t, c) == (t+1)**2:
                    #             dp[r][c] = t+1
                    #     dp[r][c] = max(1, dp[r][c])
                    # else:
                    #     dp[r][c] = matrix[r][c]
                    dp[r][c] = min(dp[r-1][c-1], dp[r-1][c], dp[r][c-1]) + 1
                else:
                    dp[r][c] = 0
        # for r in dp:
        #     print(r)
        return max([max(i) for i in dp])**2

s = Solution()
print(s.maximalSquare(
    #  [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    #  [["0","1"],["1","0"]]
    # [["0"]]
    # [["1","0","1","0","0"],
    #  ["1","0","1","1","1"],
    #  ["1","1","1","1","1"],
    #  ["1","0","0","1","0"]]
    # [["0","0","0","1"],
    #  ["1","1","0","1"],
    #  ["1","1","1","1"],
    #  ["0","1","1","1"],
    #  ["0","1","1","1"]]
    [["0","1","1","0","1"],
     ["1","1","0","1","0"],
     ["0","1","1","1","0"],
     ["1","1","1","1","0"],
     ["1","1","1","1","1"],
     ["0","0","0","0","0"]]
))

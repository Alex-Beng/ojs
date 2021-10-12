#
# @lc app=leetcode.cn id=867 lang=python3
#
# [867] 转置矩阵
#

# @lc code=start
class Solution:
    def transpose(self, matrix: [[int]]) -> [[int]]:
        row = len(matrix)
        col = len(matrix[0])
        res = [[0]*row for _ in range(col)]
        for r in range(row):
            for c in range(col):
                res[c][r] = matrix[r][c]
                # res[r][c] = matrix[c][r]
        return res
# @lc code=end


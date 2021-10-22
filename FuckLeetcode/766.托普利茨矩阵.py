#
# @lc app=leetcode.cn id=766 lang=python3
#
# [766] 托普利茨矩阵
#

# @lc code=start
class Solution:
    def isToeplitzMatrix(self, matrix: [[int]]) -> bool:
        row = len(matrix)
        col = len(matrix[0])
        for r in range(1, row):
            for c in range(1, col):
                if matrix[r][c] != matrix[r-1][c-1]:
                    return False
        return True
# @lc code=end


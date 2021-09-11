#
# @lc app=leetcode.cn id=74 lang=python3
#
# [74] 搜索二维矩阵
#

# @lc code=start
class Solution:
    def searchMatrix(self, matrix: [[int]], target: int) -> bool:
        row = len(matrix)
        col = len(matrix[0])
        r,c = row-1, 0
        while r>=0 and c<col:
            if matrix[r][c] > target:
                r -= 1
            elif matrix[r][c] < target:
                c += 1
            else:
                return True
        return False
# @lc code=end


#
# @lc app=leetcode.cn id=1582 lang=python3
#
# [1582] 二进制矩阵中的特殊位置
#

# @lc code=start
class Solution:
    def numSpecial(self, mat: [[int]]) -> int:
        row = len(mat)
        col = len(mat[0])

        row_sums = [sum(r) for r in mat]
        col_sums = [sum([mat[r][c] for r in range(row)]) for c in range(col)]
        ans = 0
        for r in range(row):
            for c in range(col):
                if mat[r][c] and row_sums[r]==1 and col_sums[c]==1:
                    ans += 1
        return ans
# @lc code=end
#
# @lc app=leetcode.cn id=1572 lang=python3
#
# [1572] 矩阵对角线元素的和
#

# @lc code=start
class Solution:
    def diagonalSum(self, mat: [[int]]) -> int:
        N = len(mat)
        L = 0
        R = N-1
        ans = 0
        for r in range(N):
            if L!=R:
                ans += (mat[r][L]+mat[r][R])
            else:
                ans += mat[r][L]
            L += 1
            R -= 1
        return ans
# @lc code=end
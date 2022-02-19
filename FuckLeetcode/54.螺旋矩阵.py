#
# @lc app=leetcode.cn id=54 lang=python3
#
# [54] 螺旋矩阵
#

# @lc code=start
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        row = len(matrix)
        col = len(matrix[0])
        been = [[0]*col for _ in range(row)]
        i = j = 0

        ans = [matrix[0][0]]
        been[0][0] = 1
        while True:
            old_i, old_j = i, j

            j += 1
            while j<col and been[i][j]==0:
                ans.append(matrix[i][j])
                been[i][j] = 1
                j += 1
            
            j -= 1; i += 1
            while i<row and been[i][j]==0:
                ans.append(matrix[i][j])
                been[i][j] = 1
                i += 1
            
            i -= 1; j -= 1
            while j>=0 and been[i][j]==0:
                ans.append(matrix[i][j])
                been[i][j] = 1
                j -= 1
            
            j += 1; i -= 1
            while i>=0 and been[i][j]==0:
                ans.append(matrix[i][j])
                been[i][j] = 1
                i -= 1
            
            i += 1
            if old_i==i and old_j==j:
                return ans
# @lc code=end


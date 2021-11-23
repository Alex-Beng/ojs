#
# @lc app=leetcode.cn id=2022 lang=python3
#
# [2022] 将一维数组转变成二维数组
#

# @lc code=start
class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if m*n != len(original):
            return []
        ans = [[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                ans[i][j] = original[i*n+j]
        return ans
# @lc code=end
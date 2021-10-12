#
# @lc app=leetcode.cn id=832 lang=python3
#
# [832] 翻转图像
#

# @lc code=start
class Solution:
    def flipAndInvertImage(self, image: [[int]]) -> [[int]]:
        image = [r[::-1] for r in image]
        image = [[1-i for i in r] for r in image]
        return image
# @lc code=end


#
# @lc app=leetcode.cn id=661 lang=python3
#
# [661] 图片平滑器
#

# @lc code=start
class Solution:
    def imageSmoother(self, img: [[int]]) -> [[int]]:
        row = len(img)
        col = len(img[0])
        inter_img = [[0]*(col+1) for _ in range(row+1)]
        for r in range(1, row+1):
            for c in range(1, col+1):
                inter_img[r][c] = inter_img[r-1][c] + inter_img[r][c-1] \
                                - inter_img[r-1][c-1] + img[r-1][c-1]

        dst = [[0]*col for _ in range(row)]
        for r in range(row):
            for c in range(col):
                rl = max(0, r-1) 
                rr = min(row, r+2)
                cl = max(0, c-1)
                cr = min(col, c+2)

                ts = inter_img[rr][cr] - inter_img[rr][cl] - inter_img[rl][cr] + inter_img[rl][cl]
                n = (rr-rl)*(cr-cl)
                dst[r][c] = int(ts/n)
        return dst
# @lc code=end

s = Solution()
s.imageSmoother(
    [[1,1,1],
     [1,0,1],
     [1,1,1]]
)
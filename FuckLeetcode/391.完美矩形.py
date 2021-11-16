 #
# @lc app=leetcode.cn id=391 lang=python3
#
# [391] 完美矩形
#

# @lc code=start
class Solution:
    def isRectangleCover(self, rectangles: [[int]]) -> bool:
        xl = min([rect[0] for rect in rectangles])
        xr = max([rect[2] for rect in rectangles])
        yl = min([rect[1] for rect in rectangles])
        yr = max([rect[3] for rect in rectangles])
         
        area_sum = sum([abs(rect[3]-rect[1])*abs(rect[2]-rect[0]) for rect in rectangles])
        print([abs(rect[3]-rect[1])*abs(rect[2]-rect[0]) for rect in rectangles])
        print(area_sum, abs(xr-xl)*abs(yr-yl))
        return area_sum == (xr-xl)*(yr-yl)
# @lc code=end
s = Solution()
s.isRectangleCover(
    [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
)


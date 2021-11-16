 #
# @lc app=leetcode.cn id=391 lang=python3
#
# [391] 完美矩形
#

# @lc code=start
class Solution:
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        xl = min([rect[0] for rect in rectangles])
        xr = max([rect[2] for rect in rectangles])
        yl = min([rect[1] for rect in rectangles])
        yr = min([rect[3] for rect in rectangles])
        
        area_sum = sum([(rect[3]-rect[1])*(rect[2]-rect[0]) for rect in rectangles])
        print(area_sum, (xr-xl)*(yr-yl))
        return area_sum == (xr-xl)*(yr-yl)
# @lc code=end
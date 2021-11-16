 #
# @lc app=leetcode.cn id=391 lang=python3
#
# [391] 完美矩形
#

# @lc code=start
class Solution:
    def isRectangleCover(self, rectangles: [[int]]) -> bool:
        if len(rectangles)==1:
            return True
        # 点 
        pnt2times = dict()
        for rect in rectangles:
            x1,y1,x2,y2 = rect
            tps = [
                (x1,y1),
                (x2,y2),
                (x1,y2),
                (x2,y1)
            ]
            for p in tps:
                if p in pnt2times:
                    pnt2times[p] += 1
                else:
                    pnt2times[p] = 1
        one_ps = [p for p in pnt2times if pnt2times[p]==1]
        odd_ps = [p for p in pnt2times if pnt2times[p]&1]
        
        # print(one_ps, max(pnt2times.values()), pnt2times)
        if len(one_ps) != 4 or len(odd_ps)!=len(one_ps):
            return False
        one_p_xl = min([p[0] for p in one_ps])
        one_p_xr = max([p[0] for p in one_ps])
        one_p_yl = min([p[1] for p in one_ps])
        one_p_yr = max([p[1] for p in one_ps])
        # 面积
        xl = min([rect[0] for rect in rectangles])
        xr = max([rect[2] for rect in rectangles])
        yl = min([rect[1] for rect in rectangles])
        yr = max([rect[3] for rect in rectangles])
         
        area_sum = sum([abs(rect[3]-rect[1])*abs(rect[2]-rect[0]) for rect in rectangles])
        return xl==one_p_xl and xr==one_p_xr and yl==one_p_yl and yr==one_p_yr and area_sum==(xr-xl)*(yr-yl) 
# @lc code=end
s = Solution()
s.isRectangleCover(
    # [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
    [[0,0,1,1],[0,1,3,2],[1,0,2,2]]
)


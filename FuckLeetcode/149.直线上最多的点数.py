#
# @lc app=leetcode.cn id=149 lang=python3
#
# [149] 直线上最多的点数
#

# @lc code=start
class Solution:
    def maxPoints(self, points: [[int]]) -> int:
        def gcd(a,b):
            if a%b:
                return gcd(b, a%b)
            else:
                return b

        def simpFrac(y,x):
            # 最简分式
            g = gcd(y,x)
            y //= g
            x //= g
            return y,x

        def getkb(p1, p2):
            dx = p1[0]-p2[0]
            dy = p1[1]-p2[1]
            if dx == 0:
                return float('inf'), p1[0]
            else:
                dy,dx = simpFrac(dy,dx)
                return dy, dx, p1[1]-dy*p1[0]//dx
        n = len(points)
        if n==1:
            return 1
        k2pnt = dict()
        for i in range(1, n):
            for j in range(0, i):
                pi = points[i]
                pj = points[j]
                kb = getkb(pi, pj)
                if kb in k2pnt:
                    k2pnt[kb].add(tuple(pi))
                else:
                    k2pnt[kb] = {tuple(pi), tuple(pj)}
        return max([len(i) for i in k2pnt.values()])
# @lc code=end

s = Solution()
res = s.maxPoints(
    # [[1,1],[2,2],[3,3]]
    # [[0,0],[4,5],[7,8],[8,9],[5,6],[3,4],[1,1]]
    # [[4,5],[4,-1],[4,0]]
    [[-6,-1],[3,1],[12,3]]

)
print(res)
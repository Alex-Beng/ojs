from typing import List

class CustomFunction:
    # Returns f(x, y) for any given positive integers x and y.
    # Note that f(x, y) is increasing with respect to both x and y.
    # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    def f(x, y):
        return x + y

class Solution:
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        x1, y1 = 1, 1
        x2, y2 = 1000, 1000
        f = customfunction.f

        # x方向上二分
        while True:
            ox1, ox2 = x1, x2

            mid_x = (x1 + x2) // 2
            if f(mid_x, y2) < z:
                x1 = mid_x
            if f(mid_x, y1) > z:
                x2 = mid_x
            # print(x1, y1, x2, y2)
            if ox1 == x1 and ox2 == x2:
                break
        # print()
        # y方向上
        while True:
            oy1, oy2 = y1, y2
            
            mid_y = (y1 + y2) // 2
            if f(x2, mid_y) < z:
                y1 = mid_y
            if f(x1, mid_y) > z:
                y2 = mid_y
            # print(x1, y1, x2, y2)
            if oy1 == y1 and oy2 == y2:
                break
        # print(x1, y1, x2, y2)
        # 可能结果在x1 y1, x2 y2组成的矩形里
        ans = []
        for x in range(x1, x2+1):
            for y in range(y1, y2+1):
                if f(x, y) == z:
                    ans.append([x, y])

        # print(ans)
        return ans
    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        f = customfunction.f
        y1 = 1000
        ans = []
        for x1 in range(1, 1001):
            while y1 and f(x1, y1) > z:
                # 一直向下
                y1 -= 1
            if y1 == 0:
                break
                
            if f(x1, y1) == z:
                ans.append([x1, y1])

        return ans
s = Solution()
r = s.findSolution(CustomFunction, z=5)
print(r)
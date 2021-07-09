class Solution:
    def countPoints(self, points: List[List[int]], queries: List[List[int]]) -> List[int]:
        ans = [0]*len(queries)
        def in_cc(pnt, circle):
            if (pnt[0]-circle[0])**2 + (pnt[1]-circle[1])**2 <= circle[2]**2:
                return True
            else:
                return False
        for pnt in points:
            for idx,cc in enumerate(queries):
                if in_cc(pnt, cc):
                    ans[idx] += 1
        return ans
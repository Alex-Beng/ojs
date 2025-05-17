from typing import List

class Solution:
    def maxScore(self, n: int, edges: List[List[int]]) -> int:
        outDeg = {}
        for e in edges:
            outDeg[e[0]] = outDeg.get(e[0], 0) + 1
            outDeg[e[1]] = outDeg.get(e[1], 0) + 1
        
        gType = 1 if 1 in outDeg.values() else 0
        
        if n == 1:
            return 1
        n1 = n
        n2 = n-1
        res = n1 * n2
        # print(res)

        while n2 >= 1:
            if n2 == 1:
                break
            if n2 == 2:
                res += n1
                n1 = 2
                n1 = 1
                break
            
            res += n1 * (n2 - 1)
            # print(res)
            res += n2 * (n2 - 2)
            # print(res)
            n1 -= 2
            n2 -= 2
        res = res + n1 * n2 if not gType else res
        return res

INPUT = [
    # (4,  [[0,1],[1,2],[2,3]])
    (6, [[0,3],[4,5],[2,0],[1,3],[2,4],[1,5]])
]
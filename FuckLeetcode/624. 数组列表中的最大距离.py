from typing import List

class Solution:
    def maxDistance(self, arrays: List[List[int]]) -> int:
        mins = [a[0] for a in arrays]
        maxs = [a[-1] for a in arrays]
        N = len(arrays)
        res = 0
        currMin = mins[0]
        currMax = maxs[0]
        for i in range(1, N):
            res = max(res, abs(currMin-maxs[i]))
            res = max(res, abs(currMax-mins[i]))

            if mins[i] < currMin:
                currMin = mins[i]
            if maxs[i] > currMax:
                currMax = maxs[i]
        
        return res

INPUT = [
    ([[1,2,3],[4,5],[1,2,3]], ),
]
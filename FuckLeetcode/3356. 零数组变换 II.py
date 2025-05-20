from typing import List

class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        N = len(nums)
        K = len(queries)

        L = 0
        R = K
        while L < R:
            mid = (L+R) // 2
            
            diff = [0] * (N + 1)
            for l, r, v in queries[:mid]:
                diff[l] += v
                diff[r + 1] -= v

            # print(diff)
            for i in range(1, N):
                diff[i] += diff[i - 1]
            # print(diff)
            res = True
            for i in range(N):
                if nums[i] - diff[i] > 0:
                    res = False
            if res:
                R = mid
            else:
                L = mid + 1

        mid = L    
        diff = [0] * (N + 1)
        for l, r, v in queries[:mid]:
            diff[l] += v
            diff[r + 1] -= v
        for i in range(1, N):
            diff[i] += diff[i - 1]
        res = True
        for i in range(N):
            if nums[i] - diff[i] > 0:
                res = False
        return L if res else -1

INPUT = [
    # ([2,0,2], [[0,2,1],[0,2,1],[1,1,3]])
    # ([4,3,2,1], [[1,3,2],[0,2,1]])
    # ([5], [[0,0,5],[0,0,1],[0,0,3],[0,0,2]])
    ([7,6,8], [[0,0,2],[0,1,5],[2,2,5],[0,2,4]])
]
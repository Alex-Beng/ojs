from typing import List
import heapq

class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        N = len(nums)
        K = len(queries)
        queries.sort(key=lambda k: k[0])

        qrq = []
        currSum = 0
        diff = [0] * (N+1)
        j = 0
        for i, n in enumerate(nums):
            currSum += diff[i]
            while j < K and queries[j][0] == i:
                heapq.heappush(qrq, -queries[j][1])
                j += 1
            while currSum < n and qrq and - qrq[0] >= i:
                r = -heapq.heappop(qrq)
                diff[r + 1] -= 1
                currSum += 1
            if currSum < n:
                return -1
        return len(qrq)
            

        
        diffSum = [0] * (N+1)
        left = 0
        for i in range(N):
            diffSum[i] += (diffSum[i-1] + diff[i-1] + diff[i])
            if nums[i] <= diffSum[i]:
                continue
            pickNum = nums[i] - diffSum[i]

            if pickNum > len(qrq):
                return -1
            
            for j in range(pickNum):
                l, r = heapq.heappop(qrq)
                r = -r
                if l > i:
                    print("b")
                    return -1
                if l < i:
                    l = j
                diff[l] += 1
                diff[r+1] -= 1
            
            while len(qrq):
                l, r = heapq.heappop(qrq)
                r = -r
                if l < i:
                    if i <= r:
                        heapq.heappush(qrq, (i, -r))
                    else:
                        left += 1
                        break
                else:
                    heapq.heappush(qrq, (l, -r))
                    break
                
        return len(qrq) + left

INPUT = [
    # ([2,0,2], [[0,2],[0,2],[1,1]])
    ([0,0,1,1,0], [[3,4],[0,2],[2,3]])
]
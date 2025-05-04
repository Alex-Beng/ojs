class Solution:
    def leastBricks(self, wall: 'List[List[int]]') -> int:
        n = len(wall)
        
        inter2nums = {}
        for r in wall:
            tempSum = 0
            for b in r:
                tempSum += b
                inter2nums[tempSum] = inter2nums.get(tempSum, 0) + 1
            C = tempSum
        inter2nums.pop(C, 0)
        if not inter2nums:
            return n
        
        maxInter = max(inter2nums, key=inter2nums.get)
        print(inter2nums)
        return n - inter2nums[maxInter]

INPUT = [
    ([[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]], ),
    ([[1],[1],[1]], )
]
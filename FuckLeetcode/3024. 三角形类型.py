from typing import List

class Solution:
    def triangleType(self, nums: List[int]) -> str:
        n2t = {}
        maxL = max(nums)
        for n in nums:
            n2t[n] = n2t.get(n, 0) + 1
        
        if sum(nums) - maxL <= maxL:
            return "none"
        
        if 3 in n2t.values():
            return "equilateral"
        elif 2 in n2t.values():
            return "isosceles"
        else:
            return "scalene"
        
        pass
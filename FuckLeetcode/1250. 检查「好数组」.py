from typing import List
from functools import cache, reduce
from math import gcd

class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        global gcd # why ?
        return reduce(gcd, nums) == 1

        @cache
        def gcd(a, b):
            a, b = (b, a) if b>a else (a, b)
            if b == 1:
                return 1
            elif b == 0:
                return a
            else:
                return gcd(a%b, b)
        n = len(nums)
        if n == 1:
            return nums[0]==1
        all_gcd = nums[0]
        for i in range(1, n):
            if all_gcd == 1:
                break
            num = nums[i]
            all_gcd = gcd(all_gcd, num)
        return all_gcd == 1
s = Solution()
r = s.isGoodArray(
    # [12,5,7,23]
    # [29,6,10]
     [3,]
)
print(r)
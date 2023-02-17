from typing import List
from collections import Counter
from functools import reduce

class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        t = reduce(lambda a, b: a^b, nums, 0)
        if t==0:
            return True
        num2times = Counter(nums)
        n_sig = 0
        for t in num2times.values():
            n_sig += t&1
        
        return n_sig&1 != 1
s = Solution()
s.xorGame(
    [1,1,2,3,4]
)
from typing import List
from collections import Counter

class Solution:
    def numberOfPairs(self, nums: List[int]) -> List[int]:

        return [sum([t//2 for t in Counter(nums).values()]), sum([t%2 for t in Counter(nums).values()])]
s = Solution()
r = s.numberOfPairs(
    [1,3,2,1,3,2,2]
)
print(r)
from functools import lru_cache

class Solution:
    @lru_cache(None)
    def numberOfSteps(self, num: int) -> int:
        if num==0:
            return 0
        else:
            return self.numberOfSteps(num-1)+1 if num&1 else self.numberOfSteps(num//2)+1
class Solution:
    def smallestNumber(self, n: int) -> int:
        n |= n >> 1
        n |= n >> 2
        n |= n >> 4
        n |= n >> 8
        return n
        pass
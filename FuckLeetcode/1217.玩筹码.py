class Solution:
    def minCostToMoveChips(self, position: 'List[int]') -> int:
        n = len(position)
        evens = 0
        for p in position:
            if p&1:
                evens += 1
        return min(evens, n-evens)
INPUT = [
    ([1,2,3],),
    ([2,2,2,3,3], )
]
from typing import List

class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        val2weigh = dict()
        for v, w in items1:
            val2weigh[v] = val2weigh.get(v, 0) + w
        for v, w in items2:
            val2weigh[v] = val2weigh.get(v, 0) + w
        return sorted(list(val2weigh.items()), key=lambda k: k[0])
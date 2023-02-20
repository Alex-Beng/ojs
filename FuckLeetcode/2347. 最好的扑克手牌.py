from typing import List

class Solution:
    def bestHand(self, ranks: List[int], suits: List[str]) -> str:
        if len(set(suits)) == 1:
            return "Flush"
        h = Counter(ranks)
        if len(h) == 5:
            return "High Card"
        for b in h.values():
            if b > 2:
                return "Three of a Kind"
        return "Pair"

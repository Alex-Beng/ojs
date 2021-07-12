class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        is_j = dict()
        for j in jewels:
            is_j[j] = 1
        ans = 0
        for s in stones:
            if s in is_j:
                ans += 1
        return ans
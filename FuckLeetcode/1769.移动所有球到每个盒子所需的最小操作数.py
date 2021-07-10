class Solution:
    # DP做就是O(n), xjb做就O(n^2)
    def minOperations(self, boxes: str) -> List[int]:
        ans = []
        for idx,box in enumerate(boxes):
            ans.append( sum([ abs(idx-iidx) for iidx, i in enumerate(boxes) if i=='1' ]) )
        return ans
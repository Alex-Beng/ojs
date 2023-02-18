class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        return max(left+[n-i for i in right])
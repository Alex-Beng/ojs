class Solution:
    def threeConsecutiveOdds(self, arr: 'List[int]') -> bool:
        status = 0
        maxStatus = -1
        for n in arr:
            if n&1:
                status += 1
            else:
                status = 0
            maxStatus = max(maxStatus, status)
        return maxStatus >= 3
        
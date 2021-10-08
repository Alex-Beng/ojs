class Solution:
    def distributeCandies(self, candyType: [int]) -> int:
        candy_n = len(set(candyType))
        n = len(candyType)
        return min(candy_n, n//2)
        
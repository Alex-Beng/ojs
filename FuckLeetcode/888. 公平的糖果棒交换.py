class Solution:
    def fairCandySwap(self, aliceSizes: [int], bobSizes: [int]) -> [int]:
        asum = sum(aliceSizes)
        bsum = sum(bobSizes)
        wanted_sum = (asum+bsum)//2

        aliceSizes = set(aliceSizes)
        bobSizes = set(bobSizes)

        a_delta = wanted_sum-asum
        for n in aliceSizes:
            if a_delta+n in bobSizes:
                return [n, a_delta+n]
        
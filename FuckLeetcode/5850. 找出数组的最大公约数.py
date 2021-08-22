class Solution:
    def findGCD(self, nums: [int]) -> int:
        def gcd(a, b):
            mi = min(a, b)
            ma = max(a, b)
            if mi==0:
                return ma
            else:
                return gcd(mi, ma%mi)
        mi = min(nums)
        ma = max(nums)
        return gcd(mi, ma)
s = Solution()
print(s.findGCD(
    #  [2,5,6,9,10]
    # [7,5,6,8,3]
     [3,3]
))
class Solution:
    def increasingTriplet(self, nums: [int]) -> bool:
        n = len(nums)
        small = 2**32
        mid = 2**32
        for n in nums:
            if n <= small:
                small = n
            elif n <= mid:
                mid = n
            else:
                return True
        return False

s = Solution()
print(s.increasingTriplet(
    # [1,2,3,4,5]
    # [5,4,3,2,1]
    [2,1,5,0,4,6]
))
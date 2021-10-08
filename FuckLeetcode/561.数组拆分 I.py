class Solution:
    def arrayPairSum(self, nums: [int]) -> int:
        nums.sort()
        return sum([n for i,n in enumerate(nums) if i&1==0])

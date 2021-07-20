class Solution:
    def minPairSum(self, nums) -> int:
        nums.sort()
        # print(nums)
        sums = [nums[i]+nums[-i-1] for i in range(len(nums)//2)]
        # print(sums)
        return max(sums)

s = Solution()
s.minPairSum([3,5,2,3])
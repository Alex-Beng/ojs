class Solution:
    def dominantIndex(self, nums: [int]) -> int:
        n = len(nums)
        if n==1:
            return 0

        nums = [(nums[i],i) for i in range(n)]
        nums.sort(key=lambda k: k[0])
        if nums[-1][0]>=nums[-2][0]*2:
            return nums[-1][1]
        else:
            return -1
s = Solution()
print(s.dominantIndex(
    [1,2,3,4]

))
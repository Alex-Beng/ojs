class Solution:
    def kthLargestNumber(self, nums: [str], k: int) -> str:
        nums.sort(key=lambda k:int(k), reverse=True)
        # print(nums)
        return nums[k-1]
s = Solution()
s.kthLargestNumber(
    ["3","6","7","10"],4
)
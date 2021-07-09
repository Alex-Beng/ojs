class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        ans = []
        for idx,num in enumerate(nums):
            ans.append(nums[nums[idx]])
        return ans
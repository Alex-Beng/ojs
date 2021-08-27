class Solution:
    def createTargetArray(self, nums: [int], index: [int]) -> [int]:
        ans = []
        n = len(nums)
        for i in range(n):
            ans.insert(index[i], nums[i])
        # print(ans)
        return ans
s = Solution()
s.createTargetArray(
     [0,1,2,3,4], [0,1,2,2,1]
)